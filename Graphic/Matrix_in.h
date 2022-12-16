#ifndef MATRIX_IN_H
#define MATRIX_IN_H
#include<Graph_lib/GUI.h>
#include "../Logic/matrix.h"
#include "../Logic/sqr_matrix.h"
#include "../Logic/column.h"
#include "../Logic/row.h"

namespace Graph_lib {

struct Matrix_in : Widget
{
    Matrix_in(Point xy, int w, int h, int x, int y);

    int attach (In_box& b);
    int attach (In_box* p);
    void attach (Window& win);

    std::vector<long double> read_vector(); // read vector from in_boxes
    Matrix read_matrix();
    Sqr_matrix read_sqr_matrix();
    Row read_row();
    Column read_column();


    void show ();  // show all in_boxes
    void hide ();   // hide all in_boxes

private:
    Vector_ref<In_box> in_boxes; // container in_boxes
    int count_row;
    int count_column;
};

}


#endif // MATRIX_IN_H
