#include <iostream>

using namespace std;

const int LEV1=5000;
const int LEV2=15000;
const int LEV3=35000;

int main()
{
	 int input;
	double tax=0;
	while(cout<<"Enter your annual income in tvarps( input<0 or not a digite to quit):"&& 
		(cin>>input && input>=0))
	{
		if(input<=LEV1)
			tax=0;
		else if(input>LEV1 && input<=LEV2)
			tax=(input-LEV1)*0.10;
		else if(input>LEV2 && input<=LEV3)
			tax=(input-LEV2)*0.15+(LEV2-LEV1)*0.10;
		else if(input>LEV3)
			tax=(input-LEV3)*0.20+(LEV3-LEV2)*0.15+(LEV2-LEV1)*0.10;
		cout<<"tax:"<<tax<<"\n";
	};
	return 0;
}
