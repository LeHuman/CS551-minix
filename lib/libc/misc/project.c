#include <sys/cdefs.h>
#include <sys/featuretest.h>
#include <sys/types.h>
#include <minix/include/lib.h>

int get_trap_count(u_int64_t* trap_count_ptr){
    message m;
    int ret = _syscall(PM_PROC_NR, PM_GETTRAPCOUNT, &m);
    if(ret >= 0){
        trap_count_ptr = &m.m_m1.m1ull1;
    }
    return ret;
}
int reset_trap_count(){
    message m;
    return (_syscall(PM_PROC_NR, PM_RESETTRAPCOUNT, &m));
}
int get_msg_count(u_int64_t* msg_count_ptr){
    message m;
    int ret = _syscall(PM_PROC_NR, PM_GETMSGCOUNT, &m);
    if(ret >= 0){
        msg_count_ptr = & m.m_m1.m1ull1;
    }
    return ret;
}
int reset_msg_count(){
    message m;
    return (_syscall(PM_PROC_NR, PM_RESETMSGCOUNT, &m));
}