#include <iostream>
using namespace std;

double division(int a, int b)
{
    if( b == 0  )
    {
        throw "Division by zero condition!";
    }

    cout <<"it is normal"<<endl;
    return (a/b);
}

int main ()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << "Result:" << z << endl;

    }catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;

}

