#include <iostream>
#include "11-2.h"
#include <cmath>
const double Rad_to_deg=57.2957795130823;
namespace CVECTOR
{
	CVector::CVector()
	{
		x=y=0;
		mode='r';
	}

	void CVector::set_x(double mag, double ang)
	{
		x=mag*cos(ang);
	}
	void CVector::set_y(double mag,double ang)
	{
		y=mag*sin(ang);
	}
	CVector::CVector(double n1, double n2, char form)
	{
		mode = form;
		if(form=='r')
		{
			x=n1;
			y=n2;
		}
		else if(form=='p')
		{
			set_x(n1,n2/Rad_to_deg);
			set_y(n1,n2/Rad_to_deg);
		}
		else
		{
			std::cout<<"Incorrect 3rd argument to CVector()--";
			std::cout<<"Vector set to 0\n";
			x=y=0;
			mode='r';
		}
	}
	double CVector::magval()const
	{
		return sqrt(x*x+y*y);
	}
	double CVector::angval()const
	{
		if(x==0&&y==0)
			return 0;
		else
			return atan2(y,x);
	}
	void CVector::polar_mode()
	{
		mode='p';
	}

	void CVector::rect_mode()
	{
		mode='r';
	}

	void CVector::set(double n1, double n2, char form)
	{
		mode=form;
		if(mode=='r')
		{
			x=n1;
			y=n2;
		}
		else if(mode=='p')
		{
			set_x(n1,n2/Rad_to_deg);
			set_y(n1,n2/Rad_to_deg);
		}
		else
		{
			std::cout<<"Incorrect 3rd argument to CVector()--";
			std::cout<<"Vector set to 0\n";
			x=y=0;
			mode='r';
		}
	}

	CVector CVector::operator -(const CVector &b) const
	{
		return CVector(x-b.x,y-b.y);
	}

	CVector CVector::operator -() const
	{
		return CVector(-x,-y);
	}

	CVector CVector::operator *(double n) const
	{
		return CVector(x*n,y*n);
	}

	CVector CVector::operator +(const CVector &b) const
	{
		return CVector(x+b.x,y+b.y);
	}

	CVector operator*(double n,const CVector &a)
	{
		return a*n;
	}

	std::ostream & operator<<(std::ostream &os,const CVector &v)
	{
		if(v.mode=='r')
			os<<"(x,y)=("<<v.x<<","<<v.y<<")";
		else if(v.mode=='p')
		{
			os<<"(m,a)=("<<v.magval()<<","<<v.angval()<<")";
		}
		else
			os<<"Vector object mode is invalid";
		return os;
	}
	CVector::~CVector()
	{
	}
}