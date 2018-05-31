#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void interrupt()
{
	printf("Interrupt call begin\n");
	sleep(3);
	printf("Interrupt call back end\n");
}

int main()
{
	signal(SIGINT,interrupt);
	printf("set call back func for SIGINT\n");
	sleep(10);
	printf("normal end\n");
	return 0;
}
