#include <iostream>
#include "11-6.h"


cStonewt::cStonewt()
{
	mode='s';
	stone=0;
	pounds=pds_left=0.0;
}

cStonewt::cStonewt(double lbs)
{
	mode='f';
	stone=int(lbs)/lbs_per_stn;
	pds_left=int(lbs)%lbs_per_stn+lbs-int(lbs);
	pounds=lbs;
}

cStonewt::cStonewt(int stn, double lbs)
{
	mode='s';
	stone=stn;
	pds_left=lbs;
	pounds=stn*lbs_per_stn+lbs;
}

cStonewt::~cStonewt()
{
}

cStonewt cStonewt::operator +(const cStonewt &c) const
{
	cStonewt total;
	total.stone=stone+c.stone;
	total.pds_left=pds_left+c.pds_left;
	total.pounds=pounds+c.pounds;
	return total;
}

cStonewt cStonewt::operator -(const cStonewt &c) const
{
	cStonewt diff;
	diff.stone=stone-c.stone;
	diff.pds_left=pds_left - c.pds_left;
	diff.pounds=pounds - c.pounds;
	return diff;
}

cStonewt cStonewt::operator *(double n) const
{
	cStonewt mult;
	mult.stone=stone*n;
	mult.pds_left= pds_left * n;
	mult.pounds = pounds * n;
	return mult;
}

std::ostream & operator <<(std::ostream &os,const cStonewt &c)
{
	using std::cout;
	using std::endl;
	if(c.mode=='s')
	{
		cout<<"Stonewt: "<<c.stone<<" stone."<<endl;
	}
	else if(c.mode=='f')
	{
		cout<<"Stonewt: "<<c.pounds<<" pounds."<<endl;
	}
	else if(c.mode=='i')
	{
		cout<<"Stonewt: "<<(int)c.pounds<<" pounds."<<endl;
	}
	else
	{
		cout<<"format is not right!"<<endl;
	}
	return os;
}

bool operator >(const cStonewt &a,const cStonewt &b)
{
	if(a.pounds>b.pounds)
		return true;
	else
		return false;
}
bool operator <(const cStonewt &a,const cStonewt &b)
{
	if(a.pounds<b.pounds)
		return true;
	else 
		return false;
}
bool operator ==(const cStonewt &a,const cStonewt &b)
{
	if(a.pounds==b.pounds)
		return true;
	else
		return false;
}
std::istream & operator >>(std::istream &is,cStonewt &c)
{
	std::cout<<"enter Stonewt stone,pds_left,pounds:"<<std::endl;
	is>>c.stone;
	is>>c.pds_left;
	is>>c.pounds;
	return is;
}