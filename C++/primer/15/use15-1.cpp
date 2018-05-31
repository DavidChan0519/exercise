#include <iostream>
#include "15-1.h"
int main(void)
{
    Tv s20;
    std::cout << "Initial settings for 20\" TV:\n";
    s20.settings();
    s20.onoff();
    s20.chanup();
    std::cout << "\nAdjusted settings for 20\" TV:\n";
    s20.settings();

    Remote grey;

    grey.set_chan(s20, 10);
    grey.volup(s20);
    grey.volup(s20);
    std::cout << "\n20\" settings after using remote\n";
    s20.settings();

    Tv s27(Tv::On);
    s27.set_mode();
    grey.set_chan(s27,28);
    std::cout << "\n27\" settings:\n";
    s27.settings();
    grey.show_style();    // check mode
    s27.rmode(grey);         // change mode
    grey.show_style();    // recheck mode
    s27.onoff();            // turn set off
    s27.rmode(grey);        // try changing mode again
    grey.show_style();     // check result

    return 0;
}
