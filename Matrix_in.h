#ifndef MATRIX_IN_H
#define MATRIX_IN_H

#include "matrix.h"
#include "GUI.h"

namespace Graph_lib {

struct Matrix_in : Widget
{
    Matrix_in(Point xy, int w, int h, int x, int y);
    Vector_ref<In_box> in_boxes;
    int count_row;
    int count_column;

    int attach (In_box& b);
    int attach (In_box* p);
    void attach (Window& win);

    Matrix read_matrix(); // read all boxes

    void show ();  // show all in_boxes
    void hide ();   // hide all in_boxes
};

}


#endif // MATRIX_IN_H
