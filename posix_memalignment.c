#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *ptr = NULL;
	int align= 256;
	int size = 1024;
	int ret = 0;

	ret = posix_memalign(&ptr, align, size);
	if (ret < 0) {
		printf("alloc mem failed\n");
		return ret;
	}
	printf("addr:%p\n",ptr);	
	snprintf(ptr,1024,"hello world\n");
	printf("result:%s\n",(char *)ptr);
	
	return 0;
}
