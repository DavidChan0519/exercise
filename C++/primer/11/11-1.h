#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
namespace CVECTOR
{
	class CVector{
	private:
		double x;
		double y;
		double mag;
		double ang;
		char mode;

		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		CVector();
		CVector(double n1,double n2,char form='r');
		void set(double n1,double n2,char form='r');
		~CVector();
		double xval()const{return x;};
		double yval()const{return y;};
		double magval()const{return mag;};
		double angval()const {return ang;};

		void polar_mode();
		void rect_mode();

		CVector operator +(const CVector &b)const;
		CVector operator -(const CVector &b)const;
		CVector operator -()const;
		CVector operator *(double n)const;

		friend CVector operator *(double n,const CVector &a);
		friend std::ostream & operator<<(std::ostream &os,const CVector &v);
	};
}
#endif