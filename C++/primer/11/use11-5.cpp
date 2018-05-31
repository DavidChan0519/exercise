#include <iostream>
#include "11-5.h"


int main(void)
{
     using std::cout;

     CStonewt fullback(245.5);
     CStonewt cornerback(13, 5.2);
     cout << fullback;
     cout << cornerback;
     cornerback.set_mode('i');
     cout << cornerback;
     CStonewt lump;
     lump = fullback + cornerback;
     cout << lump;
     fullback = fullback * 1.1;
     cout << fullback;
     lump = lump - fullback;
     cout << lump;
     lump = 1.3 * lump;
     lump.set_mode('f');
     cout << lump<<fullback;

     return 0;
}
