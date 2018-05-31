#include <iostream>
int Fill_array(double ar[], int size);
void Show_array(const double ar[], int size);
void Reverse_array(double ar[], int size);
const int LIMIT = 10;

int main( )
{
    using namespace std;
    double values[LIMIT];
    
    int entries = Fill_array(values, LIMIT);
    cout << "Array values:\n";
    Show_array(values, entries);
    cout << "Array reversed:\n";
    Reverse_array(values, entries);
    Show_array(values, entries);    
    cout << "All but end values reversed:\n";
    Reverse_array(values + 1, entries - 2);
    Show_array(values, entries);

    return 0;
}

int Fill_array(double ar[], int size)
{
    using namespace std;
    int n;
    cout << "Enter up to " << size << " values (q to quit):\n";
    for (n = 0; n < size; n++)
    {
        cin >> ar[n];
        if (!cin)
            break;
    }
    return n;
}

void Show_array(const double ar[], int size)
{
    using namespace std;
    int n;
    for (n = 0; n < size; n++)
    {
        cout << ar[n];
        if (n % 8 == 7)
            cout << endl;
        else
            cout << ' ';
    }
    if (n % 8 != 0)
        cout << endl;
}
void Reverse_array(double ar[], int size)
{
    int i, j;
    double temp;
    
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
}
