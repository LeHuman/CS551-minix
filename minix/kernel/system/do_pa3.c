#include "kernel/system.h"
#include <minix/endpoint.h>

/*===========================================================================*
 *                                do_niceto                            *
 *===========================================================================*/
int do_niceto(struct proc *caller_ptr, message *m_ptr) {
    //msg_calls = 0;
    return (OK);
}

/*===========================================================================*
 *                                do_morecache                           *
 *===========================================================================*/
int do_morecache(struct proc *caller_ptr, message *m_ptr) {
    //kernel_calls = 0;
    return (OK);
}

/*===========================================================================*
 *                                do_morezone                           *
 *===========================================================================*/
int do_morezone(struct proc *caller_ptr, message *m_ptr) {
    //m_ptr->m_m1.m1ull1 = kernel_calls;
    return (OK);
}