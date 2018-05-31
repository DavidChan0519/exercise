#ifndef _15_2_H
#define _15_2_H
#include <iostream>

class hmeanecp:public std::logic_error
{
public: 
	hmeanecp():std::logic_error("hmean() invalic arguments:a = -b \n"){};
};
class gmeanecp:public std::logic_error
{
public:
	gmeanecp():std::logic_error("gmean() arguments should be >=0\n"){};
};
#endif