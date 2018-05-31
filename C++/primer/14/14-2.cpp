#include <iostream>
#include "14-2.h"
using std::cout;
using std::endl;
using std::cerr;
using std::cin;


void Wine::GetBottles()
{
    if (years < 1)
    {
        cout << "No space allocated for data\n";
        return;
    }

    cout << "Enter " << Label() <<
            " data for " << years << " year(s):\n";
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year: ";
        cin >> PairArray::first()[i];
        cout << "Enter bottles for that year: ";
        cin >> PairArray::second()[i];
    }
}

void Wine::Show() const
{
    cout << "Wine: " << Label() << endl;
    cout << "\tYear\tBottles\n";
    for (int i = 0; i < years; i++)
        cout << '\t' << PairArray::first()[i] 
             << '\t' << PairArray::second()[i] << endl;
}

