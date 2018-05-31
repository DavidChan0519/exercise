#include <linux/module.h>  
#include <linux/highmem.h>  
#include <asm/uaccess.h>  //copy_to_user  copy_from_user
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/device.h>

#define MODULE_NAME "hepeng"  
#define HEPENG_TEST 0x0  //request code  
   
#define HEPENG_TEST_OK 0    //reply code  
#define HEPENG_TEST_UNKNOWN_OPTION -1 //reply code  
#define HEPENG_TEST_UNKNOWN_DEV -2   //reply code  
   
#define TEST_IOC_MAGIC 'k'    //device type  
   
struct COMMAND_STRU_T  
{  
    short op;   
    short error;  
};//Params transfers between server and client  
   
int hepeng_cmd(struct COMMAND_STRU_T *cmd)  
{  
    switch (cmd->op)  
    {     
        case HEPENG_TEST:  
            printk("hepeng_cmd: this is a test\n");  
            cmd->error = HEPENG_TEST_OK;  
            break;  
        default:  
            printk("hepeng_cmd: error option\n");  
            cmd->error = HEPENG_TEST_UNKNOWN_OPTION;  
            return -1;   
    }     
    return 0;  
}  


long hepeng_ioctl(struct file *file, unsigned int iCmd, unsigned long arg)
{  
    int ret_val;  
    struct COMMAND_STRU_T *cmd = (struct COMMAND_STRU_T*)  
                 kmalloc(sizeof(struct COMMAND_STRU_T), GFP_KERNEL);  
    if (!cmd)  
    {     
        printk("hepeng_ioctl: failed to allocate spcmd\n");  
        goto ioctl_error1;  
    }     
    if (copy_from_user (cmd, (long *)arg, sizeof(struct COMMAND_STRU_T)))  
    {  
        printk("hepeng_ioctl: failed to copy from user\n");  
        goto ioctl_error2;  
    }

    printk("=== current pid:%d ===\n", current->pid);
    ret_val = hepeng_cmd(cmd);  
    if (copy_to_user ((long *)arg, cmd, sizeof(struct COMMAND_STRU_T)))  
    {  
        printk("hepeng_ioctl: failed to copy to user\n");  
        goto ioctl_error2;  
    }  
    kfree(cmd);  
    return  0;  
   
ioctl_error2:  
    kfree(cmd);  
ioctl_error1:  
    return -1;  
}  

static int hepeng_open(struct inode *inode, struct file *file)
{
	printk("open...\n");
	return 0;
}

static int hepeng_close(struct inode *inode, struct file *file)
{
	printk("close...\n");
	return 0;
}

int sp_major; //global variable

static const struct file_operations module_params =  
{  
	.owner = THIS_MODULE, 
	.open =  hepeng_open,
	.release = hepeng_close,
	.unlocked_ioctl = hepeng_ioctl,  
};//disorder assignment  

static struct class *cls;

int test_init(void)  
{  
    sp_major = register_chrdev(0, MODULE_NAME, &module_params);//register a character device  
    if (sp_major < 0)  
    {  
        printk(MODULE_NAME "failed to initialize\n");  
        return -1;  
    }  

    cls = class_create(THIS_MODULE, "hepeng");

    device_create(cls, NULL, MKDEV(sp_major, 0), NULL, "hepeng"); /* /dev/hepeng */
    printk(MODULE_NAME ":initialize ok (Major Num:%d)\n",sp_major);  
    return 0;  
}

void test_clean(void)  
{  
    printk(MODULE_NAME ":quit module\n");  
    unregister_chrdev(sp_major, MODULE_NAME);//unregister a character device  
}  
   
module_init(test_init);//load module  
module_exit(test_clean);//quit module  
   
MODULE_DESCRIPTION("Only A Test");  
MODULE_AUTHOR("He Peng");  
MODULE_LICENSE("GPL v2");  
