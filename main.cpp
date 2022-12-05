#include <iostream>

#include "Calc_window.h"

using namespace Graph_lib;

int main()
{
    Calc_window winMy{Point{100, 100}, 1200, 600, "Calc_window"};

    gui_main();

    return 0;
}
