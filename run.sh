qemu-system-x86_64 -rtc base=utc -net user -net nic -m 1G -hda minix.img
#qemu-system-i386 -s -m 256 -drive format=raw,file=minux/src/minix_x86.img
#qemu-system-i386 -net user -net nic -s -m 256 -cdrom minux/src/minix_x86.img -drive format=raw,file=fs.img -boot d

#qemu-system-i386 -net user -net nic -s -m 256 -hda minux/src/minix_x86.img -drive format=raw,file=fs.img -boot d
#qemu-system-i386 -net user -net nic -s -m 256 -drive id=hd0,format=raw,file=minux/src/minix_x86.img -drive id=hd1,file=fs.img


#qemu-system-i386 -net user -net nic -s -m 256 -drive id=hd0,format=raw,file=minux/src/minix_x86.img
#qemu-system-i386 -net user -net nic -s -m 256 -drive id=hd0,format=raw,file=minix.iso