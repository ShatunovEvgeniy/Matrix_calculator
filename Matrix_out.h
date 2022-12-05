#ifndef MATRIX_OUT_H
#define MATRIX_OUT_H

#include "Matrix_in.h"
#include "GUI.h"

namespace Graph_lib {

struct Matrix_out : Widget
{
    Matrix_out(Point xy, int w, int h, Matrix mat);
    Vector_ref<Out_box> out_boxes;
    Matrix matrix;

    int attach (Out_box& b);
    int attach (Out_box* p);
    void attach (Window& win);

    void put();
    void show ();
    void hide ();
};

}

#endif // MATRIX_OUT_H
