#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "atomic.h"
#include "futex.h"
#include "sgx_urts.h"
#include "Enclave_u.h"

static volatile int num_tasks = 0;
static volatile int main_task_status = 0;
static volatile int any_fatal_error = 0;

static int BEGIN_TASK(void) {
    return a_fetch_and_add(&num_tasks, 1) == 0;
}

static void END_TASK(void) {
    if (a_fetch_and_add(&num_tasks, -1) == 1) {
        futex_wakeup(&num_tasks);
    }
}

struct task_thread_data {
    int is_main_task;
    sgx_enclave_id_t eid;
};

static void* __run_task_thread(void* _data) {
    int status = 0;
    struct task_thread_data* data = _data;

    sgx_status_t sgx_ret = libos_run(data->eid, &status);
    if(sgx_ret != SGX_SUCCESS) {
        // TODO: deal with ECALL error
        printf("ERROR: ECall libos_run failed\n");
        any_fatal_error = 1;
    }

    if (data->is_main_task) main_task_status = status;

    free(data);
    END_TASK();
    return NULL;
}

int run_new_task(sgx_enclave_id_t eid) {
    int ret = 0;
    pthread_t thread;

    struct task_thread_data* data = malloc(sizeof(*data));
    data->is_main_task = BEGIN_TASK();
    data->eid = eid;

    if ((ret = pthread_create(&thread, NULL, __run_task_thread, data)) < 0) {
        free(data);
        END_TASK();
        return ret;
    }
    pthread_detach(thread);

    return 0;
}

int wait_all_tasks(void) {
    int cur_num_tasks;
    while ((cur_num_tasks = a_load(&num_tasks)) != 0) {
        futex_wait(&num_tasks, cur_num_tasks);
    }
    return any_fatal_error ? -1 : main_task_status;
}
