#include "kernel/system.h"
#include <lib.h>
#include <minix/endpoint.h>

/*===========================================================================*
 *                                do_trapcount                                  *
 *===========================================================================*/
int do_inittrapcount(struct proc *caller_ptr, message *m_ptr) {
    kernel_calls = 0;
    task_calls = 0;
    return (OK);
}