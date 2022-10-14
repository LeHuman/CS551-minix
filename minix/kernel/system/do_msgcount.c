#include "kernel/system.h"
#include <minix/endpoint.h>

/*===========================================================================*
  *                                do_trapcount                                  *
  *===========================================================================*/
int do_msgcount(struct proc *caller_ptr, message *m_ptr)
{
        return(OK);
}