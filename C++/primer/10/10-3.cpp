#include <iostream>
#include <string>
#include "10-3.h"

using namespace std;

//cGolf::cGolf()
//{
//	m_name="no name";
//	m_hac=0;
//}

cGolf::cGolf(const std::string name, const int hac)
{
	m_name=name;
	m_hac=hac;
}

cGolf::~cGolf()
{
	cout<<"call ~cGolf!\n";
}
cGolf cGolf::setGolf(std::string na, const int ha)
{
	//cout<<"use temp so ~cGolf!\n";
	return *this=cGolf(na,ha);//template variable
}

void cGolf::show() const
{
	cout<<"name:"<<m_name<<"  hac:"<<m_hac<<endl;
}

