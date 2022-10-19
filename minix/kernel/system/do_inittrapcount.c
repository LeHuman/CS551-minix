#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/glo.h"

/*===========================================================================*
  *                                do_trapcount                                  *
  *===========================================================================*/
int do_inittrapcount(struct proc *caller_ptr, message *m_ptr)
{
    trap_counts = 0;
    return(OK);
}