#include <iostream>
#include "10-6.h"

Move::Move(double a , double b )
{
	x=a;
	y=b;
}

Move Move::add(const Move &m) const
{
	Move temp;
	temp.x=x+m.x;
	temp.y=y+m.y;
	return temp;
}

void Move::showmove() const
{
	std::cout<<"Move("<<x<<","<<y<<")\n";
}

void Move::reset(double a , double b )
{
	x=a;
	y=b;
}
