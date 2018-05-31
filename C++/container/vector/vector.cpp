#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> test;
    for (int i = 0; i < 10; i++)
        test.push_back(i);
    cout << test[0]<<endl;
   
    vector<int> *p = &test;
    cout << p->at(0) << endl;
    return 0;
}
