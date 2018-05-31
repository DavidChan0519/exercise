#include<string>  
#include<iostream>  
#include<map>  
  
using namespace std;  
  
struct person  
{  
    string name;  
    int age;  
  
    person(string name, int age)  
    {  
        this->name =  name;  
        this->age = age;  
    }  
  
    bool operator < (const person& p) const  
    {  
        return this->age < p.age;   
    }  
};  
  
map<person,int> m;  
int main()  
{  
    person p1("Tom1",20);  
    person p2("Tom2",21);  
    person p3("Tom3",22);  
    person p4("Tom4",23);  
    person p5("Tom5",24);
  
    m.insert(make_pair(p3, 101));  
    m.insert(make_pair(p4, 102));  
    m.insert(make_pair(p5, 103));  
    m.insert(make_pair(p1, 104));  
    m.insert(make_pair(p2, 105));  
      
    for(map<person, int>::iterator iter = m.begin(); iter != m.end(); iter++)  
    {  
        cout<<iter->first.name<<"\t"<<iter->first.age<<endl; 
	cout<<iter->second << endl; 
    }  
      
    return 0;  
}
