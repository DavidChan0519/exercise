#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

jmp_buf position;
int val;

void goback()
{
	fprintf(stderr,"Interrupted\n");
	/*  跳转回被保存的断点  */
	longjmp(position,val+1);
}

int main()
{
	printf("step1...\n");
	signal(SIGINT, goback);
	/*  保存当前的堆栈环境  */
	val =setjmp(position);
	printf("step2...val:%d \n",val);

	pause();
	return 0;
}
