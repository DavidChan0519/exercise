#ifndef _11_5_H
#define _11_5_H

#include <iostream>

class CStonewt
{
private:
	static const int lbs_per_stn=14;
	int stone;
	double pds_left;
	double pounds;
	char mode;
public:
	CStonewt(double lbs);
	CStonewt(int stn,double lbs);
	CStonewt();
	~CStonewt();
	
	void set_mode(char m){mode=m;};
	CStonewt operator +(const CStonewt &c)const;
	CStonewt operator -(const CStonewt &c)const;
	CStonewt operator *(double n)const;

	friend CStonewt operator *(double n,const CStonewt &c){return c*n;};
	friend std::ostream & operator <<(std::ostream &os,const CStonewt &c);
};
#endif