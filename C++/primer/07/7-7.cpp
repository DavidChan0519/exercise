
#include <iostream>
const int Max = 5;

// function prototypes
double *fill_array(double *arstart, double *arend);
void show_array(const double *arstart, double *arend);  // don't change data
void revalue(double *arstart, double *arend,double r);

int main()
{
    using namespace std;
    double properties[Max];

    double *p = fill_array(properties, properties+Max);
    show_array(properties, p);
    cout << "Enter revaluation factor: ";
    double factor;
    cin >> factor;
    revalue(properties, p,factor);
    show_array(properties, p);
    cout << "Done.\n";
    return 0;
}

double *fill_array(double *arstart, double *arend)
{
    using namespace std;
    double temp;
	double *p=arstart;
    int i;
    for (i = 0; i < Max; i++,arstart++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        *arstart = temp;
    }
	arend=arstart;
	arstart=p;
    return arend;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double *arstart, double *arend)  // don't change data
{
   using namespace std;
   for (int i=0; arstart < arend; i++,arstart++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *arstart << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double *arstart, double *arend,double r)
{
   for (int i=0; arstart < arend; i++,arstart++)
        *arstart *= r;
}
