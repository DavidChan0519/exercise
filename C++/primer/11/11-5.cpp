#include <iostream>
#include "11-5.h"

CStonewt::CStonewt()
{
	mode='s';
	stone=0;
	pounds=pds_left=0.0;
}

CStonewt::CStonewt(double lbs)
{
	mode='f';
	stone=int(lbs)/lbs_per_stn;
	pds_left=int(lbs)%lbs_per_stn+lbs-int(lbs);
	pounds=lbs;
}

CStonewt::CStonewt(int stn, double lbs)
{
	mode='s';
	stone=stn;
	pds_left=lbs;
	pounds=stn*lbs_per_stn+lbs;
}

CStonewt::~CStonewt()
{
}

CStonewt CStonewt::operator +(const CStonewt &c) const
{
	CStonewt total;
	total.stone=stone+c.stone;
	total.pds_left=pds_left+c.pds_left;
	total.pounds=pounds+c.pounds;
	return total;
}

CStonewt CStonewt::operator -(const CStonewt &c) const
{
	CStonewt diff;
	diff.stone=stone-c.stone;
	diff.pds_left=pds_left - c.pds_left;
	diff.pounds=pounds - c.pounds;
	return diff;
}

CStonewt CStonewt::operator *(double n) const
{
	CStonewt mult;
	mult.stone=stone*n;
	mult.pds_left= pds_left * n;
	mult.pounds = pounds * n;
	return mult;
}

std::ostream & operator <<(std::ostream &os,const CStonewt &c)
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