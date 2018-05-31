#ifndef _12_1_H
#define _12_1_H
#include <iostream>

class Cow{
	char name[20];
	char *bobby;
	double weight;
public:
	Cow();
	Cow(const char *nm,const char *bo,double wt);
	Cow(const Cow &c);
	~Cow();
	Cow & operator =(const Cow &c);
	void ShowCow()const;
};
#endif
