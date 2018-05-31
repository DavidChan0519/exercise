#include <stdio.h>
#include <unistd.h>

int main()
{
	unsigned char i = 0;
	i |= ((1 << 5)|(1<<6));

	unsigned char j = 0xff;
	j &= ~((1<<5)|(1<<6));

	printf("=== i:0x%x j:0x%x ===\n",i,j);
	pause();
	return 0;
}
