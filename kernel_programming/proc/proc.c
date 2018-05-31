#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

char kernel_buff[100]={0};
static struct proc_dir_entry *test_dir, *test_entry;

ssize_t test_proc_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	copy_to_user(buf,kernel_buff,100);
	return 0;	
}

ssize_t test_proc_write(struct file *file, const char __user *buffer,size_t count, loff_t *pos)
{
	
	if (copy_from_user(kernel_buff, buffer,count))
	{
		printk("copy from user error\n");
		return -ENOMEM;
	}

	return count;
}


struct file_operations proc_fops = {
	.read = test_proc_read,
	.write = test_proc_write,
	.owner = THIS_MODULE,
};

static __init int test_proc_init(void)
{
	test_dir = proc_mkdir("test_dir", NULL);
	if (test_dir != NULL)
	{
		test_entry = proc_create("test_rw",0777,test_dir,&proc_fops);
		if (test_entry != NULL)
		{
			return 0;
		}
	}
	printk("create proc dir done\n");
	return -ENOMEM;
}

static __exit void test_proc_cleanup(void)
{
	printk("remove proc dir done\n");
	remove_proc_entry("test_rw",test_dir);
	remove_proc_entry("test_dir", NULL);
}


module_init(test_proc_init);
module_exit(test_proc_cleanup);
MODULE_AUTHOR("David Chan");
MODULE_DESCRIPTION("proc example");
MODULE_LICENSE("GPL v2");
