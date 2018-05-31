#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile;
	char data[100]={0};	

	outfile.open("afile.dat");
	cout << "writing to the file" <<endl;
	cout << "enter your name:";
	
	cin.getline(data,100);
	outfile << data << endl;
	
	cout << "enter your age:";
	cin >> data;
	cin.ignore();
	outfile << data << endl;
	outfile.close();

	ifstream infile;
	infile.open("afile.dat");
	cout <<"reading from file "<< endl;
	infile >> data;
	cout << data <<endl;
	infile >> data;
	cout << data << endl;
	
	infile.close();
	return 0;

}
