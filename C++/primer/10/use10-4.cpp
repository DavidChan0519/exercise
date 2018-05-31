#include <iostream>
#include "10-4.h"

int main()
{
    using SALES::cSales;
    
    double vals[3] = {2000, 3000, 5000};
    cSales forFiji(vals, 3);
    forFiji.showSales();
    
    cSales red;
    red.showSales();
    red.setSales();
    red.showSales();
    
    return 0;
}
