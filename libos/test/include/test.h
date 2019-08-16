#ifndef __TEST_H
#define __TEST_H

#include <stdio.h>

#define _STR(x)             #x
#define STR(x)              _STR(x)
#define MIN(a, b)               ((a) <= (b) ? (a) : (b))
#define MAX(a, b)               ((a) >= (b) ? (a) : (b))
#define ARRAY_SIZE(array)   (sizeof(array)/sizeof(array[0]))


typedef int(*test_case_func_t)(void);

typedef struct {
    const char*             name;
    test_case_func_t        func;
} test_case_t;

#define TEST_CASE(name)     { STR(name), name }

#define throw_error(msg)    while(1) {                      \
    printf("\t\tERROR: %s in func %s at line %d of file %s\n",  \
           (msg), __func__, __LINE__, __FILE__);            \
    return -1;                                              \
}

int test_suite_run(test_case_t* test_cases, int num_test_cases) {
    for (int ti = 0; ti < num_test_cases; ti++) {
        test_case_t* tc = &test_cases[ti];
        if (tc->func() < 0) {
            printf("  func %s - [ERR]\n", tc->name);
            return -1;
        }
        printf("  func %s - [OK]\n", tc->name);
    }
    return 0;
}

#endif /* __TEST_H */
