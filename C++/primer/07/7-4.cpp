#include <iostream>
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;
    double mtotal;
    double probability1, probability2;
    cout << "Enter total number of game card choices and\n"
            "number of picks allowed for the field:\n";
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "Enter total number of game card choices "
                "for the mega number:\n";
        if (!(cin >> mtotal))
            break;
        cout << "The chances of getting all " << choices << " picks is one in "
             << (probability1 = probability(total, choices) ) << ".\n";
        cout << "The chances of getting the megaspot is one in "
             << (probability2 = probability(mtotal, 1) ) << ".\n";
        cout << "You have one chance in ";
        cout << probability1 * probability2;      // compute the probability
        cout << " of winning.\n";
        cout << "Next set of numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ; 
    return result;
}
