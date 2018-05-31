#include<iostream>
using namespace std;
void ConstTest1(){
    const int a = 5;
    int *p;
    p = const_cast<int*>(&a);
    (*p)++;
    cout<<a<<endl;
    cout<<*p<<endl;
    
}
void ConstTest2(){
    int i;
    cout<<"please input a integer:";
    cin>>i;
    const int a = i;
    int &r = const_cast<int &>(a);
    r++;
    cout<<a<<endl;
}
int main(){
    ConstTest1();
    ConstTest2();
    return 0;
}
