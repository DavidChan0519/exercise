#ifndef _14_5_H
#define _14_5_H
#include <iostream>
#include <string>

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string &fn,const std::string &ln,const std::string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
	friend std::ostream &operator<<(std::ostream &os,const abstr_emp &a);

	virtual ~abstr_emp()=0{};
};

class employee:public abstr_emp
{
public:
	employee();
	employee(const std::string &fn,const std::string &ln,const std::string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class manager:virtual public abstr_emp
{
	
private:
	int inchargeof;
protected:
	int InchageOf()const{return inchargeof;};
	int &InchargeOf(){return inchargeof;};
public:
	manager();
	manager(const std::string &fn,const std::string &ln,const std::string &j,int ico=0);
	manager(const manager &m);
	manager(const abstr_emp & e,int ico):abstr_emp(e),inchargeof(ico){};
	virtual void ShowAll()const;
	virtual void SetAll();
};
class fink:public virtual abstr_emp
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo()const{return reportsto;};
	std::string &ReportsTo(){return reportsto;};
public:
	fink();
	fink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rpo);
	fink(const abstr_emp &e,const std::string &rpo);
	fink(const fink & e);
	virtual void SetAll();
	virtual void ShowAll()const;
};

class highfink:public manager,public fink
{
public:
	highfink():manager(),fink(){};
	highfink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rpo,
		int ico):abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){};
	highfink(const abstr_emp &e,const std::string &rpo,int ico):abstr_emp(e),manager(e,ico),fink(e,rpo){};
	highfink(const fink & f,int ico):abstr_emp(f),fink(f),manager(f,ico){};
	highfink(const manager &m,const std::string &rpo):abstr_emp(m),manager(m),fink(m,rpo){};
	highfink(const highfink &h):abstr_emp(h),manager(h),fink(h){};
	virtual void SetAll(){manager::SetAll();fink::SetAll();};
	virtual void ShowAll()const{manager::ShowAll();fink::ShowAll();};
};
#endif

