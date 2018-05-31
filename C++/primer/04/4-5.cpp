#include <iostream>

struct CandyBar {
    char brand[40];
    double weight;
    int calories;
};

int main()
{
	using namespace std;
	CandyBar snack={"Mocha Munch",2.3,350};
	cout<<"brand:"<<snack.brand<<endl;
	cout<<"weight:"<<snack.weight<<endl;
	cout<<"calories:"<<snack.calories<<endl;
	return 0;
}
