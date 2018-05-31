#include <iostream>
#include <string.h>
using namespace std;

template <class T>
int compare(const T left, const T right)
{
    std::cout <<"in template<class T>..." <<std::endl;
    return (left - right);
}


template < >
int compare(const char* left, const char* right)
{
    std::cout <<"in special template< >..." <<std::endl;

    return strcmp(left, right);
}


//函数模板
template<class T>
bool IsEqual(T t1,T t2){
    return t1==t2;
}

template<> //函数模板特化
bool IsEqual(char *t1,char *t2){
    return strcmp(t1,t2)==0;
}

int main( )
{
    compare(1, 4);

    const char *left = "gatieme";
    const char *right = "jeancheng";
    compare(left, right);


    char str1[]="abc";
    char str2[]="abc";
    cout<<"函数模板和函数模板特化"<<endl;
    cout<<IsEqual(1,1)<<endl;
    cout<<IsEqual(str1,str2)<<endl;

    return 0;
}
