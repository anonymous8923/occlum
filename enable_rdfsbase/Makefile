obj-m += enable_rdfsbase.o

KERNEL_MAKE := $(MAKE) -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(PWD) 

all:
	$(KERNEL_MAKE) modules

# Use install and uninstall targets for debug and developement purpose
install:
	sudo insmod enable_rdfsbase.ko

uninstall:
	sudo rmmod enable_rdfsbase.ko

clean:
	$(KERNEL_MAKE) clean
	$(RM) *.o.ur-safe
