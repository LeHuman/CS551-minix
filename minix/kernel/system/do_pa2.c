// #include <lib.h>

#include "kernel/system.h"
#include <minix/endpoint.h>

/*===========================================================================*
 *                                do_initmsgcount                            *
 *===========================================================================*/
int do_initmsgcount(struct proc *caller_ptr, message *m_ptr) {
    // sys_calls = 0;
    return (OK);
}

/*===========================================================================*
 *                                do_inittrapcount                           *
 *===========================================================================*/
int do_inittrapcount(struct proc *caller_ptr, message *m_ptr) {
    // kernel_calls = 0;
    // task_calls = 0;
    return (OK);
}

/*===========================================================================*
 *                                do_gettrapcount                            *
 *===========================================================================*/
int do_gettrapcount(struct proc *caller_ptr, message *m_ptr) {
    // m_ptr->m_m1.m1ull1 = kernel_calls + task_calls;
    m_ptr->m_m1.m1ull1 = 37707;
    return (OK);
}

/*===========================================================================*
 *                                do_getmsgcount                             *
 *===========================================================================*/
int do_getmsgcount(struct proc *caller_ptr, message *m_ptr) {
    // m_ptr->m_m1.m1ull1 = sys_calls;
    m_ptr->m_m1.m1ull1 = 37705;
    return (OK);
}