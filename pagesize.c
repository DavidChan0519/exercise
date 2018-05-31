#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("page size:%d\n",getpagesize());
	return 0;
}
