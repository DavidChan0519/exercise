#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
	time_t time1;
	time_t time2;
	clock_t clock1;
	clock_t clock2;

	time1 = time(NULL);
	sleep(5);
	time2 = time(NULL);
	printf("1st: cost time:%f\n",difftime(time2,time1));

	clock1 = clock();
	sleep(5);
	clock2 = clock();
	printf("2nd: cost time:%f\n",(double)(clock2-clock1)/CLOCKS_PER_SEC);
	
	return 0;
}

