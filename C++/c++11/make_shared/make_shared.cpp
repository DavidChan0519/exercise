#include <iostream>
#include <memory>

using namespace std;


void foo(shared_ptr<int> &i)
{
    (*i)++;
}

int main()
{
    shared_ptr<int> pt = make_shared<int>(15);
    cout << "before: " << *pt << endl;
    foo(pt);
    cout << "after : " << *pt << endl;
    return 0;
}
