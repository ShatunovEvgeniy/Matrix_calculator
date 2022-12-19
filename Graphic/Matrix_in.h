#ifndef MATRIX_IN_H
#define MATRIX_IN_H
#include "GUI.h"
#include "matrix.h"
#include "sqr_matrix.h"
#include "column.h"
#include "row.h"

namespace Graph_lib {

class Matrix_in : public Widget
{
public:
    Matrix_in(Point xy, int w, int h, int count_rows, int count_columns);

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
    int attach (In_box& b);
    int attach (In_box* p);
};

}


#endif // MATRIX_IN_H
