#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	signal(SIGINT,SIG_IGN);
	printf("====\n");
	sleep(10);
	printf("=== exit ===\n");
	return 0;

}
