#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/clock.h"

/*===========================================================================*
 *                                do_niceto                            *
 *===========================================================================*/
int do_niceto(struct proc *caller_ptr, message *m_ptr) {
	struct proc *p;
	int proc_nr;
	int priority, quantum, cpu;

	if (!isokendpt(m_ptr->m_lsys_krn_schedule.endpoint, &proc_nr))
		return EINVAL;

	p = proc_addr(proc_nr);

	/* Try to schedule the process. */
	priority = m_ptr->m_lsys_krn_schedule.priority;
	quantum = p->p_quantum_size_ms;
	cpu = p->p_cpu;

	return sched_proc(p, priority, quantum, cpu, 0);
}

/*===========================================================================*
 *                                do_morecache                           *
 *===========================================================================*/
int do_morecache(struct proc *caller_ptr, message *m_ptr) {
    uint64_t buffers = m_ptr->m_m1.m1ull1;
    // lmfs_set_block_buffers(buffers);
    return (OK);
}

/*===========================================================================*
 *                                do_morezone                           *
 *===========================================================================*/
int do_morezone(struct proc *caller_ptr, message *m_ptr) {
    uint64_t sz = m_ptr->m_m1.m1ull1;
    // lmfs_set_blocksize(sz); // Uncertain if this is correct method
    return (OK);
}