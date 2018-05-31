#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> func()
{
    // same
    return nullptr;
    //return unique_ptr<int>();
}

int main()
{
    unique_ptr<int> p;
    p = func();
    if (p.get() == nullptr) {
        cout << "it is null" << endl;
    }
    return 0;
}
