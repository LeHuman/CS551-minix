#include "file.h"
#include "fs.h"
#include "lock.h"
#include "path.h"
#include "vmnt.h"
#include "vnode.h"
#include <assert.h>
#include <fcntl.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/u64.h>
#include <minix/vfsif.h>
#include <string.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int do_add_buf(void) {
    off_t newpos = 0;
    int r;

    if ((r = actual_lseek(fp, job_m_in.m_lc_vfs_lseek.fd,
                          job_m_in.m_lc_vfs_lseek.whence, job_m_in.m_lc_vfs_lseek.offset,
                          &newpos)) != OK)
        return r;

    /* insert the new position into the output message */
    job_m_out.m_vfs_lc_lseek.offset = newpos;
    return OK;
}

int do_add_zone(void) {
    return OK;
}