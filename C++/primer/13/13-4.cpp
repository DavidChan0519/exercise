#include <iostream>
#include "13-4.h"

Port::Port(const char *br,const char *st,int b)
{
	size_t size=strlen(br)+1;
	br=new char [size];
	strcpy_s(style,strlen(st)+1,st);
	style[19]='\0';
	bottles=b;
}
Port::Port(const Port &p)
{
	size_t size=strlen(p.brand)+1;
	brand=new char [size];
	strcpy_s(brand,size,p.brand);
	strcpy_s(style,strlen(p.style)+1,p.style);
	bottles=p.bottles;
}

Port &Port::operator +=(int b)
{
	bottles+=b;
	return *this;
}
Port &Port::operator -=(int b)
{
	bottles-=b;
	return *this;
}
Port &Port::operator =(const Port &p)
{
	if(this==&p)
		return *this;
	delete [] brand;
	size_t size=strlen(p.brand)+1;
	brand = new char[size];
	strcpy_s(brand,size,p.brand);
	strcpy_s(style,strlen(p.style)+1,p.style);
	style[19]='\0';
	bottles=p.bottles;
	return *this;
}

void Port::Show()const
{
	std::cout<<"Brand: "<<brand<<std::endl;
	std::cout<<"Style: "<<style<<std::endl;
	std::cout<<"Bottles: "<<bottles<<endl;
}

std::ostream &operator <<(std::ostream &os,const Port &p)
{
	os<<p.brand<<","<<p.style<<","<<p.bottles;
	return os;
}

VintagePort::VintagePort():Port()
{
	size_t size=strlen("No Name")+1;
	nickname=new char[size];
	strcpy_s(nickname,size,"No Name");
	year=0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y):Port(br,"none",b)
{
	size_t size=strlen(nn)+1;
	nickname=new char[size];
	strcpy_s(nickname,size,nn);
	year=y;
}
VintagePort::VintagePort(const VintagePort &vp):Port(vp)
{
	size_t size=strlen(vp.nickname)+1;
	nickname=new char[size];
	year=vp.year;
}

void VintagePort::Show()const
{
	using std::cout;
	using std::endl;
	Port::Show();
	cout<<"NickName: "<<nickname<<endl;
	cout<<"Year: "<<year<<endl;
}

VintagePort &VintagePort::operator =(const VintagePort &vp)
{
	if(this==&vp)
		return *this;
	Port::operator =(vp);
	delete [] nickname;
	size_t size=strlen(vp.nickname)+1;
	nickname=new char[size];
	strcpy_s(nickname,size,vp.nickname);
	year=vp.year;
	return *this;
}

std::ostream &operator <<(std::ostream &os,const VintagePort &vp)
{
	vp.Show();
	os<<"\n"<<vp.nickname<<","<<vp.year<<"\n";
	return os;
}




