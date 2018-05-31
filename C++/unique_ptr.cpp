#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    unique_ptr<string> a{new string("hello world")};
    //unique_ptr<string> a = make_unique<string>("hello world"); //only for c++14

    unique_ptr<string> b = std::move(a);
    cout <<"b:" << *b << endl;
    cout <<"a:" << *a << endl;
    return 0;
}
