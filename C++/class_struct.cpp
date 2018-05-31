#include <iostream>

using namespace std;

class A
{
    struct  node
    {
        int a;
        node()
        {
            cout << "init"<< endl;
        }

        node(int i)
        {
            a = i;
            cout <<"init by argv:" << a << endl;
        }
    };

public:
    int i= 5;
    node head;
    A(int j):head(5)
    {
        i = j;
        cout << "A init:" << i << endl;
        //head(i);
    }
};

int main()
{
    A m(1);
    cout << m.head.a << endl;
    return 0;
}
