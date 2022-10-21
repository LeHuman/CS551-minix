#include "kernel/system.h"
#include <lib.h>
#include <minix/endpoint.h>

/*===========================================================================*
 *                                do_trapcount                                  *
 *===========================================================================*/
int do_initmsgcount(struct proc *caller_ptr, message *m_ptr) {
    sys_calls = 0;
    return (OK);
}