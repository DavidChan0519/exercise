#include <stdio.h>


void func(int *bb)
{
	for (int i=0;i < 10; i++)
	{
		printf("%d %d\n",*(bb+i),bb[i]);
	}
}

int main()
{
	int *pt = NULL;
	int a = 100;
	int aa[10]={1,2,3,4,5,6,7,8,9,10};
	
	pt = (int *)&a;

	func(aa);

	printf("=== %p %p %d %d ===\n",pt,&a,a,*pt );
	return 0;
	
}
