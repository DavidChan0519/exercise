#include<iostream>  
#include <iomanip>
using namespace std;  

    struct Date{        //声明一个结构体类型Date   
        int month;      //日期中的月份   
        int day;        //日期中的天   
        int year;       //日期中的年份   
    };   

    struct Student{      //声明一个结构体类型Student   
        int num;         //声明一个整形变量num   
        char name[20];   //声明一个字符型数组name   
        char sex;        //声明一个字符型变量sex   
        int age;         //声明一个整形变量age   
        Date birthday;   //Date是结构体类型，birthday是Date的类型的变量   
        double score;     //声明一个单精度型变量   
        char addr[30];   //声明一个字符型数组addr   
   };  

int main(){  
   Student two={1,"qianshou",'m',19,10,01,1993,100.12,"JiNan"};  
   Student one=two;  
  
   cout<<one.num<<endl;  
   cout<<one.name<<endl;  
   cout<<one.sex<<endl;  
   cout<<one.age<<endl;  
   cout<<one.birthday.month<<"/"<<one.birthday.day<<"/"<<one.birthday.year<<endl;  
   cout<<one.score<<endl;  
   cout<<one.addr<<endl;   
   return 0;  
} 
