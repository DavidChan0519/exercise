#include <stdio.h>


__attribute__((constructor)) void hello()
{
	printf("1 === come first ===\n");
}


int main()
{
	printf("2 === come here ===\n");
	return 0;
}


__attribute__((destructor)) void world()
{
	printf("3 === come last ===\n");
}
