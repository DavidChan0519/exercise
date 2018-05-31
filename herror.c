#include <stdio.h>
#include <netdb.h>

int main()
{
	char *hostname="www.baidu.com";
	struct hostent *hent = gethostbyname(hostname);
	if (hent == NULL) {
		herror("can not get IP addr by hostname");
		return -1;
	}
	
	return 0;
}
	
