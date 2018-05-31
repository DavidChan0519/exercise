#include <stdio.h>
#include <time.h>

void delay(int seconds)
{
	clock_t start = clock();
	clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;

	while(clock()-start < lay)
	{

	};
}

int main()
{
	printf("=== start ===\n");
	delay(10);
	printf("=== end ===\n");
	return 0;
}
