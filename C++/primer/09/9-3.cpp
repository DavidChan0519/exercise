#include <iostream>
using namespace std;

struct chaff{
	char dross[20];
	int slag;
};
char BUF[512];

int main()
{
	chaff *p1=new chaff;
	chaff *p2;
	p2=new (BUF) chaff[2];
	
	strcpy_s(p1->dross,strlen("zhao")+1,"zhao");
	p1->slag=4;
	
	strcpy_s(p2->dross,strlen("nihao")+1,"nihao");
	p2->slag=5;

	//cout.setf(ios_base::fixed,ios_base::floatfield);
	cout<<p2<<" "<<p2->dross<<" "<<p2->slag<<endl;
	p2++;
	
	strcpy_s(p2->dross,strlen("wohao")+1,"wohao");
	p2->slag=5;
	cout<<p2<<" "<<p2->dross<<" "<<p2->slag<<endl;

	cout<<p1<<" "<<p1->dross<<" "<<p1->slag<<endl;
	

	
	return 0;
}