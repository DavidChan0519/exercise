#include <iostream>
#include "10-7.h"

cPlorg::cPlorg(char *na, int ci)
{
	strcpy_s(name,na);
	name[19]='\0';
	CI=ci;
}
void cPlorg::setCI(int ci)
{
	CI=ci;
}

void cPlorg::showplorg() const
{
	std::cout<<"PLORG NAME:"<<name
		<<"   CI:"<<CI<<std::endl;
}
