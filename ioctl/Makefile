KDIR := /usr/src/linux-headers-$(shell uname -r) #usual path: /lib/modules/(kernel name)/build  
PWD  := $(shell pwd)  

MODULE_NAME:=server
obj-m:=$(MODULE_NAME).o

all:  
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:  
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module.symvers
distclean:  
	rm -rf *.o *~ core .depend .*.cmd *.mod.c .tmp_versions Module.symvers
