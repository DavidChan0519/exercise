#include <iostream>

double h_mean(double x, double y);

int main(void)
{
    using namespace std;
    double x,y;

    cout << "Enter two numbers (a 0 terminates): ";
    while (cin >> x >> y && x * y != 0)
        cout << "harmonic mean of " << x << " and "
             << y << " = " << h_mean(x,y) << "\n";
/* or do the reading and testing in two parts:
    while (cin >> x && x != 0)
    {
        cin >> y;
        if (y == 0)
            break;
            ...
*/
    cout << "Bye\n";
    return 0;
}

double h_mean(double x, double y)
{
    return 2.0 * x * y / (x + y);
}





