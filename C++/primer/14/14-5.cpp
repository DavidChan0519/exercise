#include <iostream>
#include <string>
#include "14-5.h"

abstr_emp::abstr_emp()
{
	fname=job=lname="";
}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string &j)
{
	fname=fn;
	lname=ln;
	job=j;
}

void abstr_emp::SetAll()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout<<"Enter first name;";
	cin>>fname;
	cout<<"Enter last name:";
	cin>>lname;
	cout<<"Enter job:";
	cin>>job;
}

void abstr_emp::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout<<"first name: "<<fname
		<<"\nlast name: " <<lname
		<<"\njob: "<<job<<endl;
}

std::ostream &operator<<(std::ostream &os,const abstr_emp &a)
{
	os<<"first name: "<<a.fname<<std::endl;
	os<<"last name: " <<a.lname<<std::endl;
	os<<"job: "<<a.job<<std::endl;
	return os;
}

employee::employee():abstr_emp()
{
}

employee::employee(const std::string &fn, const std::string &ln, const std::string &j):
abstr_emp(fn,ln,j)
{
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}
void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

manager::manager():abstr_emp()
{
	inchargeof=0;
}
manager::manager(const std::string &fn,const std::string &ln,const std::string &j,int ico)
:abstr_emp(fn,ln,j),inchargeof(ico)
{
}
manager::manager(const manager &m)
:abstr_emp(m)
{
	inchargeof=m.inchargeof;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout<<"Enter inchargeof:";
	while(!(std::cin>>inchargeof))
	{
		std::cin.clear();
		std::cout<<"please input a num(int)! "<<std::endl;
		while(std::cin.get()!='\n')
			continue;
		std::cout<<"Enter inchargeof agine:";
	};
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout<<"Inchargeof: "<<inchargeof<<"\n";
}


fink::fink():abstr_emp()
{
	reportsto="";
}

fink::fink(const abstr_emp &e, const std::string &rpo):abstr_emp(e),reportsto(rpo)
{
}

fink::fink(const fink &e):abstr_emp(e)
{ 
	reportsto=e.reportsto;
}
fink::fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
:abstr_emp(fn,ln,j),reportsto(rpo)
{
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout<<"Enter reportsto:";
	std::cin>>reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout<<"Reportsto: "<<reportsto<<std::endl;
}

