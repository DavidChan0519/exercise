#ifndef _10_4_H
#define _10_4_H
namespace SALES{
	class cSales{
private:
	static const int QUARTERS =4;
	double mSales[QUARTERS];
	double mAverage;
	double mMax;
	double mMin;
public:
	cSales();
	cSales(double [],int );
	void setSales();
	void showSales() const;
	};
}
#endif
