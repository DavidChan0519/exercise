// base class
#ifndef _13_2_H
#define _13_2_H
class Cd { // represents a CD disk
	private:
	char *performers;
	char *label;
	int selections; // number of selections
	double playtime; // playing time in minutes
	public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const; // reports all CD data
	Cd & operator=(const Cd & d);
};

class Classic:public Cd
{
private:
	char *mainstr;
public:
	Classic();
	Classic(char *ms,char *s1,char *s2,int n,double x);
	Classic(char *ms,const Cd &d);
	Classic(const Classic &Cl);
	virtual ~Classic();
	virtual void Report() const;
	Classic &operator =(const Classic &Cl);
};
#endif