#ifndef _11_4_H
#define _11_4_H

#include <iostream>
namespace MYCTIME
{
	class CTime{
	private:
		int hour;
		int minutes;
	public:
		CTime();
		CTime(int h,int m=0);

		void reset(int h=0,int m=0);

		friend  CTime  operator +(const CTime &a,const CTime &b);
		friend  CTime  operator -(const CTime &a,const CTime &b);
		friend  CTime  operator *(int n,const CTime &a);
		friend  CTime  operator *(const CTime &a,int n);
		friend  CTime  operator /(const CTime &a,int n);
		friend std::ostream & operator <<(std::ostream &os,const CTime &a);
	};
}
#endif

