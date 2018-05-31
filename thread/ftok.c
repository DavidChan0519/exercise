#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	int i=0;
	for (i=1; i<256; i++) {
		printf("key=0x%x\n",ftok(".",i));
	}

	return 0;

}
