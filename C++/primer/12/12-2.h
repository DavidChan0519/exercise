#ifndef _11_2_H
#define _11_2_H

#include <iostream>

class MyString
{
private:
	char *c;
	size_t len;
	static int numstr;
	static const int LIM=80;
public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &s);
	~MyString();
	size_t length()const{return len;};
	void stringup();
	void stringlow();
	int has(char ch);
	MyString &operator =(const MyString &s);
	MyString &operator =(const char *s);
	char &operator [](int i);
	const char &operator[](int i)const;

	friend bool operator >(const MyString &a,const MyString &b);
	friend bool operator <(const MyString &a,const MyString &b);
	friend bool operator ==(const MyString &a,const MyString &b);
	friend MyString operator +(const MyString &a,const MyString &b);
	friend std::ostream &operator <<(std::ostream &os,const MyString &s);
	friend std::istream &operator >>(std::istream &is,MyString &s);

	static int HowMany();
};
#endif