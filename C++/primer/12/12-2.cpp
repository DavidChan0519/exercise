#include <iostream>
#include <stdio.h>
#include "12-2.h"
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
int MyString::numstr=0;

MyString::MyString()
{
	len=4;
	c=new char[1];
	c[0]='\0';
	numstr++;
}
MyString::MyString(const char *s)
{
	len=strlen(s);
	c=new char[len+1];
	strcpy_s(c,len+1,s);
	numstr++;
}
MyString::MyString(const MyString &s)
{
	len=s.len;
	c=new char[len+1];
	strcpy_s(c,len+1,s.c);
	numstr++;
}
MyString::~MyString()
{
	cout<<c<<"析构函数被调用"<<endl;
	numstr--;
	delete [] c;
}
int MyString::HowMany()
{
	return numstr;
}
const char &MyString::operator [](int i) const
{
	return c[i];
}
char &MyString::operator [](int i)
{
	return c[i];
}
MyString &MyString::operator =(const char *s)
{
	if(c!=NULL)
		delete [] c;
	len=strlen(s);
	c=new char [len+1];
	strcpy_s(c,len+1,s);
	return *this;
}
MyString &MyString::operator =(const MyString &s)
{
	if(this==&s)
		return *this;
	if(c!=NULL)
		delete [] c;
	len=s.len;
	c=new char[len+1];
	strcpy_s(c,len+1,s.c);
	return *this;
}
void MyString::stringlow()
{
	for(size_t i=0;i<len;i++)
	{
		c[i]=tolower(c[i]);
	}
}
void MyString::stringup()
{
	for(size_t i=0;i<len;i++)
		c[i]=toupper(c[i]);
}

int MyString::has(char ch)
{
	int count=0;
	for(size_t i=0;i<len;i++)
	{
		if(c[i]==ch)
			count++;
	}
	return count;
}

//friend fuction
bool operator >(const MyString &a,const MyString &b)
{
	return strcmp(a.c,b.c)>0;
}

bool operator <(const MyString &a,const MyString &b)
{
	return strcmp(a.c,b.c)<0;
}
bool operator ==(const MyString &a,const MyString &b)
{
	return strcmp(a.c,b.c)==0;
}

std::ostream &operator<<(std::ostream &os,const MyString &s)
{
	os<<s.c<<;
	return os;
}
std::istream &operator>>(std::istream &is,MyString &s)
{
	char temp[80];
	is.getline(temp,80);
	s=temp;
	return is;
}
MyString operator +(const MyString &a,const MyString &b)
{
	size_t l=a.len+b.len;
	char *ps=new char[l+1];
	strcpy_s(ps,a.len+1,a.c);
	strcat_s(ps,l+1,b.c);//
	MyString temp(ps);

	return temp;
}