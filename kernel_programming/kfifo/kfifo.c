#include <linux/init.h>
#include <linux/module.h>
#include <linux/kfifo.h>

MODULE_LICENSE("Dual BSD/GPL");

struct kfifo stkfifo;

static int hello_init(void)
{
	int ret =0 ;
	int i = 0;
	int val=0;
	int size = 4096;
	
	#define TEST_MASK (~(4096-1))
	
	printk("=== offset:%d ===\n",4110 & ~TEST_MASK);


	ret = kfifo_alloc(&stkfifo,size, GFP_KERNEL);
	if (ret)
	{
		return -1;
	}
	
	for (i=0 ; i<32; i++)
	{
		kfifo_in(&stkfifo, &i,sizeof(int));
	}

	ret = kfifo_out_peek(&stkfifo, &val, sizeof(int));
	if (ret != sizeof(val))
	{
		return -1;
	}

	printk("1st val:0x%x\n", val);

	while(kfifo_len(&stkfifo))
	{
		ret = kfifo_out(&stkfifo,&val,sizeof(int));
		if (ret != sizeof(int))
		{
			return -1;
		}
		printk("= pop val:0x%x=\n", val);
	}

	if (kfifo_is_empty(&stkfifo))
	{
		printk("the kfifo is empty\n");		
	}

	if (kfifo_is_full(&stkfifo))
	{
		printk("the kfifo is full\n");		
	}
	return 0;
}






static void hello_exit(void)
{
	kfifo_free(&stkfifo);
	printk(KERN_INFO "Goodbye\n");
}



module_init(hello_init);
module_exit(hello_exit);
