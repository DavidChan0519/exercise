#ifndef _11_7_H
#define _11_7_H
#include <iostream>

class complex
{
private:
    double r;
    double i;
public:
    complex();
    complex(double real);
    complex(double real, double imag);
    double magnitude();
    complex operator+(const complex & z) const;
    complex operator-(const complex & z) const;
    complex operator~() const;
    friend complex square(const complex & z);
    friend complex operator*(const complex & z, const complex & w);
    friend std::ostream & operator<<(std::ostream & os, const complex & z);
    friend std::istream & operator>>(std::istream & is, complex & z);
};
#endif

//#ifndef _11_7_H
//#define _11_7_H
//
//#include <iostream>
//
//class CComplex
//{
//private:
//	double r;
//	double i;
//public:
//	CComplex();
//	CComplex(double real);
//	CComplex(double real,double img);
//	double Magnitude();
//	
//	CComplex operator +(const CComplex &c)const;
//	CComplex operator -(const CComplex &c)const;
//	CComplex operator ~()const;
//	CComplex operator *(double n)const;
//
//	friend CComplex Square(const CComplex &c);
//	friend CComplex operator *(const CComplex &a,const CComplex &b);
//	friend CComplex operator *(double n,const CComplex &c);
//	friend std::ostream &operator <<(std::ostream &os,const CComplex &c);
//	friend std::istream &operator >>(std::istream &is, CComplex &c);
//};
//#endif