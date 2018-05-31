#include <iostream>
using namespace std;


class Box
{
private:
	int m_length;
	int m_width;
	int m_height;

public:
	Box operator+(Box &b);
	void set_length(int len);
	void set_width(int width);
	void set_height(int height);
	void show()const;
};



Box Box::operator+(Box &b)
{
	Box c;
	c.m_length = this->m_length + b.m_length;
	c.m_width = this->m_width + b.m_width;
	c.m_height = this->m_height + b.m_height;

	return c;
}


void Box::set_length(int len)
{
	m_length = len;
	cout << "update value of length:"<<len<<endl;
}


void Box::set_width(int width)
{
	m_width = width;
	cout << "update value of width:"<< width<<endl;
}

void Box::set_height(int height)
{
	m_height = height;
	cout << "update value of height:"<<height<<endl;
}

void Box::show()const
{
	cout << "length of c:"<<m_length<<endl;
	cout << "width of c:"<<m_width<<endl;
	cout << "height of c:"<<m_height << endl;
}

int main()
{
	Box a;
	Box b;
	
	a.set_length(12);
	a.set_width(53);
	a.set_height(89);

	b.set_length(43);
	b.set_width(78);
	b.set_height(21);
	
	Box c;
	c=a+b;
	c.show();
	return 0;
}
