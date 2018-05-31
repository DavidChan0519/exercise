#include <iostream>

struct CandyBar {
    char brand[40];
    double weight;
    int calories;
};

int main()
{
	using namespace std;
	CandyBar snack[3]={
		{"Mocha Munch",2.3,350},
		{"zhaoh  hang",3.2,350},
		{"niha he",3.3,234}
	};
	CandyBar *ptr_snack=new CandyBar[3];
	for(int i=0;i<3;i++)
	{
		ptr_snack[i]=snack[i];

	}
	for(int i=0;i<3;i++)
	{
		cout<<"brand:"<<snack[i].brand<<endl;
		cout<<"weight:"<<snack[i].weight<<endl;
		cout<<"calories:"<<snack[i].calories<<endl;

		cout<<"brand:"<<ptr_snack[i].brand<<endl;
		cout<<"weight:"<<ptr_snack[i].weight<<endl;
		cout<<"calories:"<<ptr_snack[i].calories<<endl;

	}
	return 0;
}
