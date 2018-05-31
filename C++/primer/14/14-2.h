#include <iostream>
#include <valarray>
#include <string>

template <class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 &first(){return a;};
	T2 &second(){return b;};
	T1  first()const {return a;};
	T2  second()const {return b;};
	Pair(const T1 &aval,const T2 &bval):a(aval),b(bval){};
	Pair(){};
};

//template <class T1,class T2>
//Pair::Pair()
//{
//}

class Wine:private Pair<std::valarray<int>,std::valarray<int>>,private std::string
{
private:
	//typedef std::valarray<int,int>PariArray;
	typedef std::valarray<int>ArrayInt;
	typedef Pair<ArrayInt,ArrayInt>PairArray;
	int years;
public:
	Wine():std::string("None"),years(0),PairArray(ArrayInt(),ArrayInt()){};
	Wine(const char *l,int y,const int yr[],const int bot[]):std::string(l),years(y),PairArray(ArrayInt(yr,y),ArrayInt(bot,y)){};
	Wine(const char *l,int y):std::string(l),years(y),PairArray(ArrayInt(0,y),ArrayInt(0,y)){};
	void GetBottles();
	const std::string  &Label()const {return (const std::string &)*this;};
	int sum()const {return PairArray::second().sum();};
	void Show()const;
};