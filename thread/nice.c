#include <stdio.h>
#include <unistd.h>

int main()
{
	nice(5);
	printf("modify the thread priority\n");
	return 0;
}
