#include <iostream>
#include <fstream>
#include <vector>
#include <string>
int main()
{
	using namespace std;

	ofstream fout;
	ifstream fin1,fin2;
	fin1.open("17-4fin1.txt");
	fin2.open("17-4fin2.txt");
	fout.open("17-4fout.txt");
	if(!fin1.is_open())
	{
		cerr<<"open file 17-4fin1.txt failed!\n";
		exit(EXIT_FAILURE);
	}
	if(!fin2.is_open())
	{
		cerr<<"open file 17-4fin2.txt failed!\n";
		exit(EXIT_FAILURE);
	}
	if(!fout.is_open())
	{
		cerr<< " open file 17-4fout.txt failed!\n";
		exit(EXIT_FAILURE);
	}
	string temp1,temp2,reasul;
	while(getline(fin1,temp1) && getline(fin2,temp2))
	{
		reasul=temp1;
		if(reasul=="")
			reasul +=temp2;
		else
			reasul +=" " + temp2;
		fout<<reasul<<endl;
	}
	while(getline(fin1,temp1))
	{
		reasul=temp1;
		fout<<reasul<<endl;
	}
	while(getline(fin2,temp2))
	{
		reasul=temp2;
		fout<<reasul<<endl;
	}
	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}



