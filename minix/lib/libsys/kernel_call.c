#define _SYSTEM 1

#include <lib.h>

#include <minix/syslib.h>
#include <minix/sysutil.h>
#include <stdio.h>

int enable_counter = 0;
int kernel_calls = 0;

int _kernel_call(int syscallnr, message *msgptr) {
    int t, r;
    t = 1;
    if (enable_counter) {
        kernel_calls++;
    }

    while (1) {
        msgptr->m_type = syscallnr;
        do_kernel_call(msgptr);
        r = msgptr->m_type;
        if (r != ENOTREADY) {
            break;
        }
        tickdelay(t++);
    }
    return r;
}
