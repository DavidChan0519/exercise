#include <iostream>
#include "cow.h"

Cow::Cow()
{
	name[0]='\0';
	hobby=NULL;
	weight=0;
}
Cow::Cow(const char *nm, const char *ho, double wt)
{

	strcpy(name,nm);
	hobby=new char[strlen(ho)+1];
	strcpy(hobby,ho);
	weight=wt;
}

Cow::Cow(const Cow &c)
{
	strcpy(name,c.name);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
}

Cow::~Cow()
{
	weight=0;
	delete [] hobby;
}

void Cow::ShowCow() const
{
	using  std::cout;
	using  std::endl;
	cout<<name<<endl;
	cout<<hobby<<endl;
	cout<<weight<<endl;
}
Cow &Cow::operator =(const Cow &c)
{
	if(hobby!=NULL)
		delete [] hobby;
	strcpy(name,c.name);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	return *this;
}