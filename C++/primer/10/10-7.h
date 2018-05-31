#ifndef _10_7_H
#define _10_7_H
#include <iostream>

class cPlorg{
	char name[20];
	int CI;
public:
	cPlorg(char *na="Plorga",int ci=50);
	void setCI(int ci);
	void showplorg()const;
};
#endif