#include <stdio.h>
#include <string.h>

int main()
{
//char s[]="ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
//char *delim="-";

char s[]="abcd efg hijk";
char *delim=" ";
char *p;

printf("%s\n",strtok(s,delim));

while((p=strtok(NULL,delim)))
{
printf("%s",p);
printf("\n");
}

return 0;
}
