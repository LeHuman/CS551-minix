#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/glo.h"

/*===========================================================================*
  *                                do_trapcount                                  *
  *===========================================================================*/
int do_trapcount(struct proc *caller_ptr, message *m_ptr)
{
      return(OK);
}