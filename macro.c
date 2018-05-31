#include <stdio.h>

#define TEST_MARCO "hello"

int main()
{
	char *ptr = NULL; 
	ptr = TEST_MARCO;
	
	printf("result:%s\n",ptr);
	return 0;
}
