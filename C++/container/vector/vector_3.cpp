#include <iostream>  
#include <map>  
#include <queue>  
#include <vector>  
  
using namespace std;  
  
int main()  
{  
   vector<int> q;  
   q.push_back(3);  
   q.push_back(1);  
   q.push_back(2);  
   for(auto &v : q)  
    cout<<v<<endl;  
   
   vector<int>w[3];  
   w[0].push_back(3);  
   w[0].push_back(1);  
   w[0].push_back(2);

   cout << "vector[0] size:" << w[0].size()<<endl;
   cout << "vector[1] size:" << w[1].size()<<endl;
   cout << "vector[2] size:" << w[2].size()<<endl;

   cout << "[0][0]:"<<w[0][0] << endl;
   if (w[1].empty()) {
	cout << "[1]" << "empty" << endl;
   }   
   
   if (w[2].empty()) {
	cout << "[2]" << "empty" << endl;
   }

   for(auto &v : w[0])  
    cout<<v<<endl;  
   
   return 0;  
}  
