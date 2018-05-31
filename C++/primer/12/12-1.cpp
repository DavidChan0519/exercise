#include <iostream>
#include "12-1.h"

Cow::Cow()
{
	name[0]='\0';
	bobby=NULL;
	weight=0;
}
Cow::Cow(const char *nm, const char *bo, double wt)
{
	strncpy_s(name,nm,20);
	name[19]='\0';
	size_t size=0;
	bobby=new char[size=strlen(bo)+1];

	strcpy_s(bobby,size ,bo);
	weight=wt;
}
Cow::Cow(const Cow &c)
{
	strcpy_s(name,c.name);
	size_t size=0;
	bobby=new char[size=strlen(c.bobby)+1];
	strcpy_s(bobby,size,c.bobby);
	weight=c.weight;
}
Cow::~Cow()
{
	name[0]='\0';
	weight=0;
	delete [] bobby;
}
void Cow::ShowCow() const
{
	std::cout<<"name:"<<name<<std::endl;
	std::cout<<"bobby:"<<bobby<<std::endl;
	std::cout<<"weight:"<<weight<<std::endl;
}
Cow &Cow::operator =(const Cow &c)
{
	if(bobby!=NULL)
		delete [] bobby;
	strcpy_s(name,c.name);
	size_t size=0;
	bobby=new char[size=strlen(c.bobby)+1];
	strcpy_s(bobby,size,c.bobby);
	weight=c.weight;
	return *this;
}

	