#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
public:
    MyString()
    {
        m_data = NULL;
        cout<<"无参构造函数"<<endl;
    }

    MyString(const char *str )
    {
        if (str ==NULL)
        {
            m_data = new char[1];
            *m_data = '\0';
        }
        else
        {
            int length;
            length = strlen(str);
            m_data = new char [length+1];

            strcpy(m_data,str);
        }
        cout<<"带参数构造函数 "<<endl;
    }

    MyString(const MyString &other)
    {
        int length;
        length = strlen(other.m_data);
        m_data = new char [length+1];
        strcpy(m_data,other.m_data);

        cout<<"拷贝构造函数"<<endl;

    }

    MyString &operator =( const MyString &other)
    {
        if ( this == &other)
        {
            return *this;
        }
        else
        {
            delete []m_data;

            int length;
            length = strlen(other.m_data);
            m_data = new char[length+1];
            strcpy(m_data,other.m_data);

            cout<<"赋值函数 "<<endl;
            return *this;
        }
    }
    ~MyString()
    {
        if (m_data)
        {
            delete []m_data;
        }
    }

private:
    char *m_data;
};

int main()
{
    cout<<"--------------测试1------------"<<endl;
    MyString str1;

    cout<<"-----------"<<endl;
    str1 = "hello";  //会调用普通构造函数、赋值函数

    cout<<"--------------测试2------------"<<endl;
    MyString str2 = "hello"; //等价于MyString str2("hello"); 


    cout<<"--------------测试3------------"<<endl;
    MyString test("TEST");

    cout<<"-----------"<<endl;
    MyString str3;

    cout<<"---- -----"<<endl;
    str3 = test ;

    cout<<"--------------测试4------------"<<endl;
    MyString str4 = test;


    return 1;
}
