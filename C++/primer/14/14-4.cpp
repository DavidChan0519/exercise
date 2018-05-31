#include <iostream>
#include <string>

#include "14-4.h"

Person::Person()
{
	firstname=lastname="";
}

Person::Person(char *first, char *last)
{
	firstname=first;
	lastname=last;
}

Person::Person(std::string first, std::string last)
{
	firstname=first;
	lastname=last;
}

void Person::Show() const
{
	std::cout<<"First Name; "<<firstname<<std::endl;
	std::cout<<"Last Name: "<<lastname<<std::endl;
}

void Person::set()
{
	std::cout<<"Enter First Name: ";
	std::cin>>firstname;
	std::cout<<"Enter Last Name: ";
	std::cin>>lastname;
}


Gunslinger::Gunslinger():Person()
{
	drawtime=0.0;
	notches=0;
}
Gunslinger::Gunslinger(char *f, char *l, double d, int n):Person(f,l),drawtime(d),notches(n)
{
}

Gunslinger::Gunslinger(const Person &p, double d, int n):Person(p),drawtime(d),notches(n)
{
}

void Gunslinger::set()
{
	using std::cin;
	Person::set();
	std::cout<<"Enter drawtime: ";
	std::cin>>drawtime;
	std::cout<<"Enter notches: ";
	std::cin>>notches;
}

void Gunslinger::Show() const
{
	Person::Show();
	std::cout<<"Drawtime: "<<Draw()<<std::endl;
	std::cout<<"Notches: "<<notches<<std::endl;
}

void PokerPlayer::Show() const
{
	Person::Show();
	std::cout<<"Card: "<<Draw()<<std::endl;
}




