/* SPDX-License-Identifier: (GPL-2.0+ OR BSD-3-Clause) */
/*
 * A kernel module to enable RDFSBASE family instructions on x86.
 *
 * Copyright (c) 2018-2019 Intel Corp. All rights reserved.
 * Author: Hongliang Tian <tatetian@gmail.com>
 */

#include <linux/compiler.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/tlbflush.h>
#include <asm/smp.h>

#define LOG(...)            printk(KERN_INFO "enable_rdfsbase: " __VA_ARGS__)

#define CR4_FSGSBASE_BIT    16
#define CR4_FSGSBASE_MASK   (1UL << CR4_FSGSBASE_BIT)


static void set_cr4_fsgsbase(void* _unused) {
    unsigned long cr4_val = cr4_read_shadow();
    int is_rdfsbase_enabled = (cr4_val & CR4_FSGSBASE_MASK) != 0;
    if (is_rdfsbase_enabled) return;

    cr4_set_bits(CR4_FSGSBASE_MASK);
}

static void clear_cr4_fsgsbase(void* _unused) {
    cr4_clear_bits(CR4_FSGSBASE_MASK);
}


int init_module(void)
{
    int cpu;
    int err;

    LOG("Loaded\n");

    for_each_online_cpu(cpu) {
        err = smp_call_function_single(cpu, set_cr4_fsgsbase, NULL, 1);

        if (err) {
            LOG("Fail to set CR4.FSGSBASE on CPU %d\n", cpu);
        }
        else {
            LOG("RDFSBASE and its friends are now enabled on CPU %d\n", cpu);
        }
    }

    return 0;
}

void cleanup_module(void)
{
    int cpu;
    int err;

    for_each_online_cpu(cpu) {
        err = smp_call_function_single(cpu, clear_cr4_fsgsbase, NULL, 1);

        if (err) {
            LOG("Fail to clear CR4.FSGSBASE on CPU %d\n", cpu);
        }
        else {
            LOG("RDFSBASE and its friends are now disabled on CPU %d\n", cpu);
        }
    }

    LOG("Unloaded\n");
}

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Hongliang Tian, Intel Corp.");
MODULE_DESCRIPTION("Enable RDFSBASE family instructions on x86");
