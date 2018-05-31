#include <iostream>
#include "13-2.h"

Cd::Cd()
{
	size_t size=0;
	performers=new char[size+1];
	performers[0]='\0';
	label=new char[size+1];
	label[0]='\0';
	playtime=0.0;
	selections=0;
};

Cd::Cd(char *s1, char *s2, int n, double x)
{
	size_t size=0;
	size=strlen(s1);
	performers=new char[size+1];
	strcpy_s(performers,size+1,s1);
	size=strlen(s2);
	label=new char[size+1];
	strcpy_s(label,size+1,s2);
	selections=n;
	playtime=x;
};
Cd::Cd(const Cd &d)
{
	size_t size=0;
	size=strlen(d.performers);
	performers=new char [size+1];
	strcpy_s(performers,size+1,d.performers);
	size=strlen(d.label);
	label=new char [size+1];
	strcpy_s(label,size+1,d.label);
	playtime=d.playtime;
	selections=d.selections;
}
Cd &Cd::operator =(const Cd &d)
{
	if(this==&d)
		return *this;
	delete [] performers;
	delete [] label;
	size_t size=0;
	size=strlen(d.performers)+1;
	performers=new char[size];
	strcpy_s(performers,size,d.performers);
	size=strlen(d.label)+1;
	label=new char[size];
	strcpy_s(label,size,d.label);
	playtime=d.playtime;
	selections=d.selections;
	return *this;
}
void Cd::Report() const
{
	std::cout<<"Performers: "<<performers<<std::endl;
	std::cout<<"Label: "<<label<<std::endl;
	std::cout<<"selections: "<<selections<<std::endl;
	std::cout<<"Playtime: "<<playtime<<std::endl;
}
Cd::~Cd()
{
	delete [] performers;
	delete [] label;
	playtime=0.0;
	selections=0;
}

Classic::Classic():Cd()
{
	mainstr=new char[1];
	mainstr[0]='\0';
}

Classic::Classic(char *ms, char *s1, char *s2, int n, double x):Cd(s1,s2,n,x)
{
	size_t size=0;
	size=strlen(ms)+1;
	mainstr=new char [size];
	strcpy_s(mainstr,size,ms);
}

Classic::Classic(const Classic &Cl):Cd(Cl)
{
	size_t size=0;
	size=strlen(Cl.mainstr)+1;
	mainstr=new char [size];
	strcpy_s(mainstr,size,Cl.mainstr);
}
Classic &Classic::operator =(const Classic &Cl)
{
	if(this==&Cl)
		return *this;
	Cd::operator =(Cl);
	delete [] mainstr;
	size_t size=0;
	size=strlen(Cl.mainstr)+1;
	mainstr=new char[size];
	strcpy_s(mainstr,size,Cl.mainstr);
	return *this;
}
void Classic::Report() const
{
	Cd::Report();
	std::cout<<"MainStr: "<<mainstr<<std::endl;
}

Classic::~Classic()
{
	delete [] mainstr;
}
