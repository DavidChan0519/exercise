#include <iostream>
#include <fstream>

using namespace std;
//在项目属性中的调试里的命令参数输入打开的文件名称
//ctrl + z  是键盘模拟文件尾标志
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
