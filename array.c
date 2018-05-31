#include <stdio.h>

struct zero
{
	int i;
	char a[0];

};


int main()
{
	struct zero test;
	test.a[0]=1;

	printf("=== size:%ld ===\n",sizeof(test));
	printf("=== a:%d===\n",test.a[0]);
	return 0;	
}
