#ifndef _10_6_H
#define _10_6_H

class Move{
	double x;
	double y;
public:
	Move(double a=0,double b=0);
	void showmove()const;
	Move add(const Move &m)const;
	void reset(double a=0,double b=0);
};
#endif