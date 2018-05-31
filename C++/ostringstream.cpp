#include <iostream>
#include <sstream>
#include <unistd.h>
using namespace std;

int main()
{
    ostringstream ostr;
    ostr.put('d');
    ostr.put('e');
    ostr << "fg";

    cout << ostr.str() << endl;
    pause();
    return 0;
}
