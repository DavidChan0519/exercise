#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t fpid;
	int count = 0;
	
	fpid = fork();
	if (fpid < 0) {
		perror("fork error\n");
		return -1;
	}	
	
	if (fpid == 0) {
		printf("i am the child process, my process id is %d\n",getpid());
		count++;
	} else {
		printf("i am the parent process, my process id is %d\n",getpid());
		count++;
	}

	printf("result:%d\n",count);
	return 0;
}
