cd minux/src
HOST_CFLAGS=-fcommon bash ./build.sh -j12 -mi386 -O ../obj.i386 -D ../obj.i386/destdir.i386 -U -u distribution
#JOBS=12 HOST_CFLAGS=-fcommon bash ./releasetools/x86_hdimage.sh
