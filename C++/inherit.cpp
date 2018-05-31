#include <iostream>
using namespace std;

class Shape
{
public:
	void setWidth(int w);
	void setHigh(int h);
protected:
	int width;
	int hight;
};

void Shape::setWidth(int w)
{
	width = w;
}

void Shape::setHigh(int h)
{
	hight = h;
}

class Pay
{
public:
	int cost(int area);

};

int Pay::cost(int area)
{
	return area * 79;
}


class Rectangle: public Shape,public Pay
{
public:
	int getArea();
};


int Rectangle::getArea()
{
	return width * hight;
}

class A
{
public:
    virtual void show()
    {
        cout << "This is A" <<endl;
    }

};

class B: public A
{
public:
    void show()
    {
        cout << "This is B" << endl;
    }

    void only()
    {
        cout << "only for B"<<endl;
    }

};


int main()
{
	Rectangle Rect;

	Rect.setWidth(2);
	Rect.setHigh(5);

	cout << "the area of rectangle:" << Rect.getArea()<<endl;
	int area = Rect.getArea();
	cout << "the cost of area:"<< Rect.cost(area)<<endl;
	A *pa = new A();
    pa->show();
    A *pb = new B();
    pb->show();
    //pb->only();

    B *pc = new B();
    pc->show();
    pc->only();

    return 0;
}
