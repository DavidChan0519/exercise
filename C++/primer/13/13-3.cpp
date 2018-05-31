#include <iostream>
#include "13-3.h"

ABC::ABC(const char *l,int r)
{
	label=new char[strlen(l)+1];
	strcpy_s(label,strlen(l)+1,l);
	rating=r;
}

ABC::ABC(const ABC &a)
{
	size_t size=0;
	size=strlen(a.label)+1;
	label=new char [size];
	strcpy_s(label,size,a.label);
	rating=a.rating;
}

void ABC::View() const
{
	std::cout<<"Label: "<<label<<std::endl;
	std::cout<<"Rating: "<<rating<<std::endl;
}

ABC &ABC::operator =(const ABC &a)
{
	if(this==&a)
		return *this;
	delete [] label;
	size_t size=0;
	size=strlen(a.label)+1;
	label=new char [size];
	strcpy_s(label,size,a.label);
	rating=a.rating;
	return *this;
}

std::ostream &operator <<(std::ostream &os,const ABC &a)
{
	os<<"Lable: "<<a.label<<"\n";
	os<<"rating: "<<a.rating<<"\n";
	return os;
}
ABC::~ABC()
{
	delete [] label;
	rating=0;
}
baseDMA::baseDMA(const char *l,int r):ABC(l,r)
{
}
void baseDMA::View()const
{
	ABC::View();
}
std::ostream &operator <<(std::ostream &os,const baseDMA &bd)
{
	os<<"Label: "<<bd.getlablel()<<"\n";
	os<<"Rating: "<<bd.getrating()<<"\n";
	return os ;
}
	

hasDMA::hasDMA(const char *s,const char *l,int r):ABC(l,r)
{
	size_t size=0;
	size=strlen(s)+1;
	style=new char [size];
	strcpy_s(style,size,s);
}
hasDMA::hasDMA(const char *s, const ABC &rs):ABC(rs)
{
	size_t size=strlen(s)+1;
	style=new char[size];
	strcpy_s(style,size,s);
}
hasDMA::hasDMA(const hasDMA &hs):ABC(hs)
{
	size_t size=strlen(hs.style)+1;
	style=new char [size];
	strcpy_s(style,size,hs.style);
}

void hasDMA::View()const
{
	ABC::View();
	std::cout<<"Style: "<<style<<std::endl;
}

hasDMA &hasDMA::operator =(const hasDMA &rs)
{
	if(this==&rs)
		return *this;
	ABC::operator =(rs);
	delete [] style;
	size_t size=strlen(rs.style)+1;
	style=new char[size];
	strcpy_s(style,size,rs.style);
	return *this;
}

std::ostream &operator <<(std::ostream &os,const hasDMA &hd)
{
	os<<"label: "<<hd.getlablel()<<"\n";
	os<<"Rating: "<<hd.getrating()<<"\n"
		<<"Style: "<<hd.style<<"\n";
	return os;
}
hasDMA::~hasDMA()
{
	delete [] style;
}

lacksDMA::lacksDMA(const char *c,const char *l,int r):ABC(l,r)
{
	strncpy_s(color,c,40);
	color[39]='\0';
}

lacksDMA::lacksDMA(const char *c,const lacksDMA &ld):ABC(ld)
{
	strncpy_s(color,c,40);
	color[39]='\0';
}

void lacksDMA::View()const
{
	ABC::View();
	std::cout<<"Color: "<<color<<std::endl;
}

std::ostream &operator <<(std::ostream &os,const lacksDMA &ld)
{
	os<<"Lebel: "<<ld.getlablel()<<"\n";
	os<<"Rating: "<<ld.getrating()<<"\n";
	os<<"Color: "<<ld.color<<"\n";
	return os;
}

	


	




