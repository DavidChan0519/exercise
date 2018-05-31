#include <linux/kernel.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	char *pchar = "mn12abcmn";
	char *end = NULL;
	unsigned long val = simple_strtoul(pchar,&end,0);

	printk("the val after translate :%lu\n",val);
	printk("end :%s\n",end);
	printk("sizeof for pointer:%lu\n",sizeof(end));
	printk("sizeof for char pointer:%lu\n",sizeof(*pchar));
	return 0;

}



static void __exit hello_exit(void)
{
	printk("exit...\n");
	return ;

}



module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
