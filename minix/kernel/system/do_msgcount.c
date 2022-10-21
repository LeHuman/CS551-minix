#include "kernel/system.h"
#include <lib.h>
#include <minix/endpoint.h>

/*===========================================================================*
 *                                do_trapcount                                  *
 *===========================================================================*/
int do_msgcount(struct proc *caller_ptr, message *m_ptr) {
    m_ptr->m_m1.m1ull1 = sys_calls;
    return (OK);
}