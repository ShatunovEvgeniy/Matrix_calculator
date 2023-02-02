#include "Logic/matrix.h"
#include "Logic/row.h"
#include "Logic/column.h"
#include "Logic/vector.h"
#include "Logic/sqr_matrix.h"
#include "Graphic/Calc_window.h"
#include "Files work/streams.h"

#include <iostream>
#include <cmath>

using namespace std;
using namespace Graph_lib;

int main()
{
    try
    {
        Calc_window winMy = {Point{100, 100}, 1200, 600, "Calc_window"};
        Graph_lib::gui_main();
    }

    catch(runtime_error e)
    {
        cerr << e.what() << endl;
    }

}
