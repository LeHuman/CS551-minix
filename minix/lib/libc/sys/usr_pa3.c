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

int increase_system_priority(unsigned long long int priority, int endpoint) {
    message m;
    memset(&m, 0, sizeof(m));
    m.m_pm_sched_scheduling_set_priority.endpoint = endpoint;
    m.m_pm_sched_scheduling_set_priority.maxprio = priority;
    m.m_pm_sched_scheduling_set_priority.user_process = 0;
    int ret = _syscall(SCHED_PROC_NR, SCHEDULING_SET_NICE, &m);
    return ret;
}

int increase_user_priority(unsigned long long int priority) {
    message m;
    memset(&m, 0, sizeof(m));
    m.m_pm_sched_scheduling_set_priority.endpoint = 1;
    m.m_pm_sched_scheduling_set_priority.maxprio = priority;
    m.m_pm_sched_scheduling_set_priority.user_process = 1;
    int ret = _syscall(SCHED_PROC_NR, SCHEDULING_SET_NICE, &m);
    return ret;
}

int increase_cache(unsigned long long int increment_value) {
    message m;
    // m.m_m1.m1ull1 = increment_value;
    m.m_m1.m1ull1 = roundup(increment_value, 4096);
    return(_syscall(VFS_PROC_NR, VFS_ADD_BUF, &m));
    // return (_kernel_call(SYS_MORECACHE, &m));
}

int increase_zone(unsigned long long int blocks_per_zone) {
    message m;
    // m.m_m1.m1ull1 = blocks_per_zone;
    m.m_m1.m1ull1 = roundup(blocks_per_zone, 4096);
    return(_syscall(VFS_PROC_NR, VFS_ADD_ZONE, &m));
    // return (_kernel_call(SYS_MOREZONE, &m));
}