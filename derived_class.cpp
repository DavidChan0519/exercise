#include <iostream>
using namespace std;

class shaped
{
public:

void setWidth(int w)
{
	width = w;
}

void setHeight(int h)
{
	height = h;
}

protected:
	int width;
	int height;

};


class rectangle: public shaped
{
public:
	int getArea()
	{
		return (width * height);
	}
};


int main()
{
	rectangle testcase;

	testcase.setWidth(2);
	testcase.setHeight(3);
	
	cout << "area:" << testcase.getArea()<<endl;
	return 0;
}
