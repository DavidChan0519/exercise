#include <iostream>
#include <fstream>

using namespace std;
//����Ŀ�����еĵ�����������������򿪵��ļ�����
//ctrl + z  �Ǽ���ģ���ļ�β��־
int main(int argc,char *argv[])
{
	ofstream outFile;
	char ch;
	outFile.open(argv[1]);
	if(!outFile.is_open())
	{
		cout<<"open file error!";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter some date:\n";
	cin.get(ch);
	while(cin && !cin.eof())
	{
		outFile<<ch;
		cin.get(ch);
	}
	outFile.close();
	return 0;
}
