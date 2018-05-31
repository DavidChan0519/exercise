#ifndef _14_4_H
#define _14_4_H

#include <iostream>

using std::string;
class Person
{
private:
	
	string firstname;
	string lastname;
public:
	Person();
	Person(char *first,char *last);
	Person(std::string first,std::string last);
	Person(const Person &p){firstname=p.firstname;lastname=p.lastname;};
	Person &operator=(const Person &p){firstname=p.firstname,lastname=p.lastname;};
	virtual ~Person(){};
	virtual void set();
	virtual void Show()const;
};

class Gunslinger:virtual public Person
{
private:
	double drawtime;
	int notches;
public:
	Gunslinger();
	Gunslinger(char *f,char *l,double d,int n);
	Gunslinger(const Person &p,double d,int n);
	virtual ~Gunslinger(){};
	
	virtual double Draw()const{return drawtime;};
	void Show()const;
	void set();
};

class PokerPlayer:virtual public Person
{
private:
public:
	PokerPlayer():Person(){}
	PokerPlayer(char *f,char *l):Person(f,l){};
	PokerPlayer(const Person &p):Person(p){};
	virtual int  Draw()const{return rand()%52+1;};
	void Show()const;

};

class BadDude:public Gunslinger,public PokerPlayer
{
private:
public:
	BadDude():PokerPlayer(),Gunslinger(){};
	BadDude(char *f,char *l,double d=0.0,int n=0):PokerPlayer(f,l),Gunslinger(f,l,d,n){};
	BadDude(const Person &p,double d=0.0,int n=0):PokerPlayer(p),Gunslinger(p,d,n){};
	double Gdraw()const{return Gunslinger::Draw();};
	int Cdraw()const{return PokerPlayer::Draw();};
	void Show()const{Gunslinger::Show();PokerPlayer::Show();};
	void set(){Gunslinger::set();};
};
#endif

