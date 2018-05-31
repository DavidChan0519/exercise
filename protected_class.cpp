#include <iostream>
using namespace std;

class box
{
protected:
	int width;

};


class childbox:box
{
public:
	int getwidth();
	void setwidth(int val);

};

int childbox::getwidth()
{
	return width;
}

void childbox::setwidth(int val)
{
	width = val;
}


int main()
{
	childbox testclass;

	testclass.setwidth(10);
	cout << "width :" << testclass.getwidth() <<endl;
	return 0;
}
