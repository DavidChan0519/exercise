#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int    fd[2],  nbytes;
	pid_t  childpid;
	char   string[]  = "Hello, world!\n";
	char   readbuffer[80]={0};

	pipe(fd);

	if((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}

	if(childpid > 0)
	{
		printf("parent thread...\n");
		/*  子进程关闭管道的读句柄  */
		close(fd[0]);
		
		sleep(3);
		/*  通过写句柄向管道写入信息  */
		write(fd[1], string, strlen(string));

	}
	else
	{
		printf("child thread...\n");
		/*  父进程关闭管道的写句柄  */
		close(fd[1]);

		/*  通过读句柄从管道读出信息 (maybe blocked) */
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received string: %s\n", readbuffer);
		exit(0);
	}

	printf("parent thread end.\n");
	return(0);
}
