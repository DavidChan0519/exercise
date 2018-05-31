#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void failure(char *s)
{
	perror(s);
	exit(1);
}



void printops(char *string, int fildes)
{
	long pos = lseek(fildes, 0, SEEK_CUR);
	
	if (pos < 0) {
		failure("lseek failed");
	}
	printf("%s , current position: %ld \n", string, pos);
}


int main()
{
	int fd;
	int pid;
	char buf[10]={0};
	
   	if ((fd=open("data",O_RDONLY)) < 0){
		failure("open failed");
	}

	read(fd, buf, 10);
	printops("Before fork",fd);
	if ((pid=fork()) < 0) {
		failure("fork failed");
	} else if (!pid) {
		printops("child before read",fd);
		read(fd, buf, 10);
		printops("child after read",fd);
	} else {
		wait(NULL);
		printops("parent after wait",fd);
	}

	return 0;
}	
