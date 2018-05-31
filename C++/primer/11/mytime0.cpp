#include <iostream>
#include "mytime0.h"

Time::Time()
{
	hours=0;
	minutes=0;
}

Time::Time(int h, int m )
{
	hours=h;
	minutes=m;
}

Time Time::Sum(const Time &t) const
{
	Time temp;
	temp.minutes=minutes+t.minutes;
	temp.hours=hours+t.hours+temp.minutes/60;
	temp.minutes=temp.minutes%60;
	return temp;
}

void Time::AddHr(int h)
{
	hours+=h;
}

void Time::AddMin(int m)
{
	minutes+=m;
	hours+=minutes/60;
	minutes %=60;
}

void Time::Reset(int h,int m)
{
	hours=h;
	minutes=m;
}

void Time::show() const
{
	std::cout<<hours<<" hours,"<<minutes<<" minutes\n";
}

Time Time::operator +(const Time &t) const
{
	Time temp;
	temp.minutes=minutes+t.minutes;
	temp.hours=hours+t.hours+temp.minutes/60;
	temp.minutes %=60;
	return temp;
}

Time Time::operator -(const Time &t)const
{
	Time diff;
	int tot1,tot2;
	tot1=t.minutes+60*t.hours;
	tot2=minutes+60*hours;
	diff.minutes=(tot2-tot1)%60;
	diff.hours=(tot2-tot1)/60;

	return diff;
}

Time Time::operator *(double n) const
{
	Time result;
	long  totalminutes=hours*n*60+minutes*n;
	result.hours=totalminutes/60;
	result.minutes=totalminutes%60;
	return result;
}