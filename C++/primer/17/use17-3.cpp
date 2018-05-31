#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char *argv[])
{
	if(argc<3)
	{
		cerr<<"Usage: "<<argv[0]<<" source-file target-file\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin(argv[1]);
	if(!fin)
	{
		cerr<<"Can't open "<<argv[1]<<" for input \n";
		exit(EXIT_FAILURE);
	}
	ofstream fout(argv[2]);
	if(!fout)
	{
		cerr<<"Can't open "<<argv[2]<<" for output \n";
		exit(EXIT_FAILURE);
	}

	char ch;
	while(fin.get(ch))
	{
		fout<<ch;
		cout<<ch;
	}
	fin.close();
	fout.close();

	return 0;
}
