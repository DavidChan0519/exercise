#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	ifstream infile;
	infile.open("./06/6-5.txt",ios_base::in|ios_base::binary);
	if(!infile.is_open())
	{
		cout<<"open failed!\n";
		exit(EXIT_FAILURE);
	}
	char ch;
	int AlphaCount=0;
	while(infile.get(ch)&&  infile.good())
	{
		if(isalpha(ch))
			AlphaCount++;
	}
	cout<<AlphaCount<<"\n";
	infile.close();
	return 0;
}
