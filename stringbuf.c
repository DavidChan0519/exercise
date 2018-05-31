#include <stdio.h>

int main()
{
	char a[5]={'a','b','c','d','e'};
	char b[5]="abcde";

	printf("a=> %s %ld\n",a,strlen(a));
        printf("b=> %s %ld\n",b,strlen(b));
	return 0;
}
