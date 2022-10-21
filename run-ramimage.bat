REM Run in powershell/cmd
cd ..\\obj.i386\\work
qemu-system-x86_64 -rtc base=utc -net user,hostfwd=tcp::10022-:22 -net nic -m 4G -kernel kernel -append "bootramdisk=1" -initrd "mod01_ds,mod02_rs,mod03_pm,mod04_sched,mod05_vfs,mod06_memory,mod07_tty,mod08_mib,mod09_vm,mod10_pfs,mod11_mfs,mod12_init"