ccflags-y += -g
ccflags-y += -I$(src)

obj-m += pwm.o
pwm-y += pwm-designware.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
