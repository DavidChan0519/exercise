#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define TIMEOUT 5
#define MAXTRIES 5
#define LINESIZE 100
#define BELL '\007'
#define TRUE 1
#define FALSE 0

/*  判断超时是否已经发生的标志  */
static int time_out;

static char inputline[LINESIZE];
char* quickreply (char* prompt);
void catch(int signum);

int main()
{
	printf("%s\n",quickreply("Input"));
	return 0;
}

char* quickreply (char* prompt)
{
	void (*was)(int);
	int ntries;
	char* answer;
	/*  设定捕捉 SIGALRM 的的关联并保存原有关联  */
	was=signal(SIGALRM,catch);
	for (ntries=0;ntries<MAXTRIES;ntries++)
	{
		time_out=FALSE;
		printf("\n%s>",prompt);
		/*  设定定时器  */
		alarm(TIMEOUT);
		/*  获取输入  */
		answer=gets(inputline);
		/*  关闭定时器  */
		alarm(0);
		if (!time_out) {
			break;
		}
	}
	/*  恢复原有的 SIGALRM 关联  */
	signal(SIGALRM,was);
	return (time_out ? ((char*) 0):answer);
}
/* SIGALRM 信号处理函数  */
void catch(int signum)
{
	/*  设定超时标志  */
	time_out=TRUE;
	printf("TIMEOUT-ALARM\n");
	/*  响铃警告  */
	putchar(BELL);
}


