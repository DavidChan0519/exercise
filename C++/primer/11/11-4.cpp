#include <iostream>
#include "11-4.h"

namespace MYCTIME
{
	CTime::CTime()
	{
		hour=minutes=0;
	}
	CTime::CTime(int h, int m )
	{
		hour=h;
		minutes=m;
	}
	void CTime::reset(int h,int m)
	{
		hour=h;
		minutes=m;
	}

	CTime operator -(const CTime &a,const CTime &b)
	{
		CTime total;
		total.minutes=(a.minutes+a.hour*60)-(b.minutes+b.hour*60);
		total.hour=total.minutes/60;
		total.minutes=total.minutes%60;
		return total;
	}
	CTime operator *(const CTime &a,int n)
	{
		CTime total;
		total.minutes=(a.minutes+a.hour*60)*n;
		total.hour=total.minutes/60;
		total.minutes=total.minutes%60;
		return total;
	}
	CTime operator *(int n,const CTime &a)
	{
		return a*n;
	}
	CTime operator /(const CTime &a,int n)
	{
		CTime total;
		total.minutes=(a.minutes+a.hour*60)/n;
		total.hour=total.minutes/60;
		total.minutes=total.minutes%60;
		return total;
	}

	CTime operator +(const CTime &a,const CTime &b)
	{
		CTime total;
		total.minutes=a.minutes+b.minutes;
		total.hour=a.hour+b.hour+total.minutes/60;
		total.minutes=total.minutes%60;
		return total;
	}
	std::ostream &operator <<(std::ostream &os,const CTime &a)
	{
		os<<a.hour<<" hours, "<<a.minutes<<" minutes"<<std::endl;
		return os;
	}
}


