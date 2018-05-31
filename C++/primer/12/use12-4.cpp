#include <iostream>
#include "12-4.h"

int main(void)
{
    using namespace std;
    Stack st(3); // create a stack of po numbers
    unsigned long temp;
    char c;

    cout << "Please enter A to add a PO,\n"
          << "P to process a PO, and Q to quit.\n";
    while (cin >> c && (c = toupper(c)) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (c != 'A' && c != 'P')
        {
            cout << "Please respond with A, P, or Q: ";
            continue;
        }
        switch (c)
        {
            case 'A': if (st.isfull())
                    cout << "stack already full\n";
                else
                {
                    cout << "Enter PO number: ";
                    cin >> temp;
                    st.push(temp);
                }
                break;
            case 'P': if (st.isempty())
                    cout << "stack already empty\n";
                else {
                    st.pop(temp);
                    cout << "Processing PO " << temp << '\n';
                }
                break;
            default: cout << "Whoops! Programming error!\n";
        }
        cout << "Please enter A to add a customer,\n"
        << "P to process a customer, and Q to quit.\n";
    }
    cout << "Done!\n";
    return 0;
}
