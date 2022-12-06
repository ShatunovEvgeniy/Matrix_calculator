#include "Matrix_out.h"

#include <sstream>

#include <vector>

using namespace Graph_lib;

/// Constructors
Matrix_out::Matrix_out(Point xy, int w, int h, Matrix mat)
    : Widget{ xy, w, h, "Matrix_in", nullptr}, matrix{mat}
{
    for(int j = 0; j < matrix.get_width(); ++j)
        for(int i = 0; i < matrix.get_length(); ++i)
            out_boxes.push_back(new Out_box{Point{xy.x + w / matrix.get_length() * i, xy.y + h / matrix.get_width() * j}, w / matrix.get_length(), h / matrix.get_width(), ""}); // last arg is the same to make a sqr
}

/// Methods
int Matrix_out::attach(Out_box& b)
{
    b.width = width;
    b.height = height;
    out_boxes.push_back (&b);
    return int(out_boxes.size()-1);
    // Menu does not delete &b
}

int Matrix_out::attach (Out_box* p)
{
    // owned.push_back(p);
    return attach (*p);
    // Menu deletes p
}

void Matrix_out::attach (Window& win) // attach all In_box
{
    for (int i = 0; i < out_boxes.size(); ++i)
        win.attach(out_boxes[i]);
    own = &win;
}

void Matrix_out::put(){
    std::vector<long double> mat = matrix.get_num();
    for(int i = 0; i < out_boxes.size(); ++i)
    {
        std::stringstream s;
        s << mat[i];
        out_boxes[i].put(s.str());
    }
}

void Matrix_out::show ()
{
    for (int i = 0; i < out_boxes.size(); ++i)
        out_boxes[i].show();
}
void Matrix_out::hide ()
{
    for (int i = 0; i < out_boxes.size(); ++i)
        out_boxes[i].hide();
}
