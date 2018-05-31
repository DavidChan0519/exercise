#include <iostream>
#include "11-7.h"  // to avoid confusion with complex.h
int main()
{
    using std::cout;
    using std::endl;
    using std::cin;

    complex a(3.0, 4.0);   // initialize to (3,4i)
    complex c;
	complex mult;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << endl;
        cout << "complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
		mult=2*c;
        cout << "2 * c is " << mult << endl;
        cout << "Enter a complex number (q to quit):\n";
    }
	complex b[3];
	for(int i=0;i<3;i++)
		cin>>b[i];
    cout << "Done!\n";
    return 0;
}
