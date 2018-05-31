#include <iostream>
#include <string.h>
#include <cstring>
#include "10-2.h"

using namespace std;

Person::Person(const std::string &ln, const char *fn )
{
	lname=ln;
	strncpy(fname,fn,24);
	fname[25]='\0';
}

void Person::FormalShow() const
{
	cout<<"lastname:"<<lname<<"  firstname:"<<fname<<endl;
}

void Person::Show()const
{
	cout<<"firstname:"<<fname<<"  lastname:"<<lname<<endl;
}
