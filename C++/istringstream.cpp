#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    istringstream istr("11.33 5 127.3");
    cout << istr.str() << endl;

    int a;
    float b;
    istr >> a;
    cout << a << endl;

    istr >> b;
    cout << b << endl;

    return 0;
}
