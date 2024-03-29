#ifndef MATRIX_OUT_H
#define MATRIX_OUT_H

#include "../Logic/Matrix.h"
#include <Graph_lib/GUI.h>

namespace Graph_lib {

class Matrix_out : public Widget
{
public:
    Matrix_out(Point xy, int w, int h, Matrix mat);

    void attach (Window& win);

    void show (); // show all out_boxes
    void hide ();  // hide all out_boxes
    void put ();

private:
    Vector_ref<Out_box> out_boxes; // container out_boxes
    Matrix matrix;
    int attach (Out_box& b);
    int attach (Out_box* p);
};

}

#endif // MATRIX_OUT_H
