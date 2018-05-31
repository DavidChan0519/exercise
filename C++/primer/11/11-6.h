#ifndef _11_6_H
#define _11_6_H

#include <iostream>
class cStonewt
{
private:
	static const int lbs_per_stn=14;
	int stone;
	double pds_left;
	double pounds;
	char mode;
public:
	cStonewt(double lbs);
	cStonewt(int stn,double lbs);
	cStonewt();
	~cStonewt();
	
	void set_mode(char m){mode=m;};
	cStonewt operator +(const cStonewt &c)const;
	cStonewt operator -(const cStonewt &c)const;
	cStonewt operator *(double n)const;
	//cStonewt operator [](int i){return this[i];}
	friend bool operator >(const cStonewt &a,const cStonewt &b);
	friend bool operator <(const cStonewt &a,const cStonewt &b);
	friend bool operator ==(const cStonewt &a,const cStonewt &b);
	friend cStonewt operator *(double n,const cStonewt &c){return c*n;};
	friend std::ostream & operator <<(std::ostream &os,const cStonewt &c);
	friend std::istream & operator >>(std::istream &is,cStonewt &c);
};
#endif