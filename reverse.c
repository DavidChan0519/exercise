#include <stdio.h>
#include <string.h>

void reverse(char *s)
{
	char *head = s;
	char *tail = s + strlen(s)-1;
	char temp = 0;

	while(head < tail) {
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
	
	return ;
}


int main()
{
	char str[]="abcdefg";
	
	printf("Before:%s\n",str);
	reverse(str);
	printf("After:%s\n",str);
	
	return 0;
}
