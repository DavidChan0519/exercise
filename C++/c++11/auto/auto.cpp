#include <iostream>
using namespace std;


int main() {
	string s("hello,world");
	for(auto &c:s)//对于s中的每个字符，c是一个引用，赋值语句将会改变s中字符的值
    		c=toupper(c);
	cout<<s<<endl;
}
