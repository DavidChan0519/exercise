#include <stdio.h>
extern char **environ;

int main()
{
	char **env = environ;
	int idx=0;

	while(*env) {
		printf("index:%d %s\n",idx++,*env);
	}
	return 0;
}
