#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int i,j;
	srand((int)time(0));
	printf("RAND MAX VAL:%d\n",RAND_MAX);
	for(i=0;i<10;i++)
	{
		printf("rand val:%d\n",rand());
		j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
		printf("%d\n" ,j);
	}
	return 0;
}
