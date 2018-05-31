#include <iostream>
#include <cmath>
#include "11-7.h"

complex::complex()
{
    r = i = 0.0;
}

complex::complex(double real)
{
    r = real;
    i = 0.0;
}

complex::complex(double real, double imag)
{
    r = real;
    i = imag;
}

double complex::magnitude()
{
    return std::sqrt(r*r + i*i);
}
complex complex::operator+(const complex & z) const
{
    complex sum;
    sum.r = r + z.r;
    sum.i = i + z.i;
    return sum;
}

complex complex::operator-(const complex & z) const
{
    complex sum;
    sum.r = r + z.r;
    sum.i = i + z.i;
    return sum;
}

complex complex::operator~() const
{
    complex conjugate;
    conjugate.r = r;
    conjugate.i = -i;
    return conjugate;
}
complex square (const complex & z)
{
    complex sq;
    sq.r = z.r * z.r - z.i * z.i;
    sq.i = 2.0 * z.r * z.i;
    return sq;
}

complex operator*(const complex & z, const complex & w)
{
    complex sq;
    sq.r = w.r * z.r - w.i * z.i;
    sq.i = w.r * z.i + w.i * z.r;
    return sq;
}


std::ostream & operator<<(std::ostream & os, const complex & z)
{
    os << '(' << z.r << ',' << z.i << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & z)
{
    std::cout << "real: ";
    if (is >> z.r)
    {
        std::cout << "imaginary: ";
        is >> z.i;
    }
    return is;
}

//#include <iostream>
//#include <cmath>
//#include "11-7.h"
//
//CComplex::CComplex()
//{
//	r=i=0.0;
//}
//
//CComplex::CComplex(double real)
//{
//	r=real;
//	i=0.0;
//}
//CComplex::CComplex(double real, double img)
//{
//	r=real;
//	i=img;
//}
//
//double CComplex::Magnitude()
//{
//	return sqrt(r*r+i*i);
//}
//
//CComplex CComplex::operator +(const CComplex &c) const
//{
//	CComplex sum;
//	sum.r=r+c.r;
//	sum.i=i+c.i;
//	return sum;
//}
//
//CComplex CComplex::operator -(const CComplex &c) const
//{
//	CComplex temp;
//	temp.r=r-c.r;
//	temp.i=i-c.i;
//	return temp;
//}
//
//CComplex CComplex::operator ~() const
//{
//	CComplex temp;
//	temp.r=r;
//	temp.i=-i;
//	return temp;
//}
//
//CComplex CComplex::operator *(double n)const
//{
//	CComplex temp;
//	temp.r=r*n;
//	temp.i=i*n;
//	return temp;
//}
//
//
////friend function
//CComplex operator *(double n,const CComplex &c)
//{
//	return c*n;
//}
//std::ostream &operator <<(std::ostream &os,const CComplex &c)
//{
//	os<<"("<<c.r<<","<<c.i<<"i)";
//	return os;
//}
//std::istream &operator >>(std::istream &is,CComplex &c)
//{
//	std::cout<<"real:";
//	if(is>>c.r)
//	{
//		std::cout<<"imaginary:";
//		if(is>>c.i)
//			return is;
//	}
//	return is;
//}
//
//CComplex operator *(const CComplex &a,const CComplex &b)
//{
//	CComplex mult;
//	mult.r=a.r*b.r-a.i*b.i;
//	mult.i=a.r*b.i+a.i*b.r;
//	return mult;
//}
//CComplex Square(const CComplex &c)
//{
//	CComplex sq;
//	sq.r=c.r*c.r-c.i*c.i;
//	sq.i=2.0 * c.r * c.i;
//	return sq;
//}
