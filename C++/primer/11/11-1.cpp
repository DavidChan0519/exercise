#include <iostream>
#include "11-1.h"
#include <cmath>
const double Rad_to_deg=57.2957795130823;
namespace CVECTOR
{
	CVector::CVector()
	{
		x=y=mag=ang=0;
		mode='r';
	}

	CVector::CVector(double n1, double n2, char form)
	{
		mode = form;
		if(form=='r')
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(form=='p')
		{
			mag=n1;
			ang=n2/Rad_to_deg;
			set_x();
			set_y();

		}
		else
		{
			std::cout<<"Incorrect 3rd argument to CVector()--";
			std::cout<<"Vector set to 0\n";
			x=y=mag=ang=0;
			mode='r';
		}
	}

	void CVector::set_ang()
	{
		if(x==0&&y==0)
			ang=0;
		else
			ang=atan2(y,x);
	}

	void CVector::set_mag()
	{
		mag=sqrt(x*x+y*y);
	}

	void CVector::set_x()
	{
		x=mag*cos(ang);
	}

	void CVector::set_y()
	{
		y=mag*sin(ang);
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
			set_mag();
			set_ang();
		}
		else if(mode=='p')
		{
			mag=n1;
			ang=n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			std::cout<<"Incorrect 3rd argument to CVector()--";
			std::cout<<"Vector set to 0\n";
			x=y=mag=ang=0;
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
			os<<"(m,a)=("<<v.mag<<","<<v.ang*Rad_to_deg<<")";
		}
		else
			os<<"Vector object mode is invalid";
		return os;
	}
	CVector::~CVector()
	{
	}
}