#include <stdio.h>

#define PAGE_MASK ( ~(4096-1) )

int main()
{
	
	int i = 3 & (16 -1);
	int j = 0x40000 & (16-1);
	int k = 17 & (16 -1);
	int m = 4096 & (~PAGE_MASK);
	unsigned n = 0xffff;
	
	printf("i=%d j=%d k=%d\n",i,j,k);
	printf("m = 0x%x \n", m);
	printf("page mask:0x%x \n",PAGE_MASK);
	printf("~(~MASK):0X%X\n",~(~n));

	int Aa = 0x8000004 & (64 -1);

	printf("val after aligned:0x%x\n",Aa);


        int Bb = 0x80000040 & (64 -1);
        printf("val after aligned:0x%x\n",Bb);

	return 0;

}
