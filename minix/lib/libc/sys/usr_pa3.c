#include <lib.h>

#include <sys/cdefs.h>
#include <sys/featuretest.h>
#include <sys/pa3.h>
#include <sys/param.h>
#include <sys/ptrace.h>
#include <sys/signal.h>


#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int increase_system_priority(const uint32_t& priority, const endpoint_t& endpoint) {
    message m;
    memset(&m, 0, sizeof(m));
    m.m_pm_sched_scheduling_set_priority.endpoint = endpoint;
    m.m_pm_sched_scheduling_set_priority.maxprio = priority;
    m.m_pm_sched_scheduling_set_priority.user_process = 0;
    int ret = _syscall(SCHED_PROC_NR, SCHEDULING_SET_NICE, &m);
    return ret;
}
int increase_user_priority(const uint32_t& priority) {
    message m;
    memset(&m, 0, sizeof(m));
    m.m_pm_sched_scheduling_set_priority.endpoint = 1;
    m.m_pm_sched_scheduling_set_priority.maxprio = priority;
    m.m_pm_sched_scheduling_set_priority.user_process = 1;
    int ret = _syscall(SCHED_PROC_NR, SCHEDULING_SET_NICE, &m);
    return ret;
}