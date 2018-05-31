#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair
{
	private:
	T1 a;
	T2 b;
	public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
	Pair() {}
};
template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
	return a;
}
template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
	return b;
}


class Wine
{
private:
	std::string label;//葡萄酒名称
	typedef std::valarray<int>ArrayInt;//葡萄酒的储存年数
	typedef Pair<ArrayInt,ArrayInt>PairArray;//葡萄酒的生产年份和数量
	int years;
	PairArray data;
public:
	Wine():label("None"),years(0),data(ArrayInt(),ArrayInt()){};
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char * l, int y);
	Wine(const char * l,const PairArray & yr_bot);
	Wine(const char * l,const ArrayInt &yr,const ArrayInt &bot);
	void GetBottles();
	const std::string &Label(){ return label;};
	int sum()const { return data.second().sum();};
	void Show()const;
};

