#include <iostream>
#include <iomanip> //格式控制
using namespace std;

int main()
{
double amount = 22.0/7;
cout <<amount <<endl; //(1)
cout <<setprecision(0) <<amount <<endl //(2)
<<setprecision(1) <<amount <<endl //(3)
<<setprecision(2) <<amount <<endl //(4)
<<setprecision(3) <<amount <<endl //(5)
<<setprecision(4) <<amount <<endl; //(6)
cout <<setiosflags(ios::fixed);
cout <<setprecision(8) <<amount <<endl; //(7)
cout <<setiosflags(ios::scientific)<<amount<<endl; //(8)
cout <<setprecision(6);
return 0;
}
