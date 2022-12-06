#include "Matrix_in.h"
#include <sstream>

#include <vector>

using namespace Graph_lib;

/// Constructors
Matrix_in::Matrix_in(Point xy, int w, int h, int x, int y)
    : Widget{ xy, w, h, "Matrix_in", nullptr}, count_row{x}, count_column{y}
{
    for(int j = 0; j < y; ++j)
        for(int i = 0; i < x; ++i)
            in_boxes.push_back(new In_box{Point{xy.x + w / x * i, xy.y + h / y * j}, w / x, h / y, ""}); // last arg is the same to make a sqr
}

/// Methods
int Matrix_in::attach(In_box& b)
{
    b.width = width;
    b.height = height;
    in_boxes.push_back (&b);
    return int(in_boxes.size()-1);
    // Menu does not delete &b
}

int Matrix_in::attach (In_box* p)
{
    // owned.push_back(p);
    return attach (*p);
    // Menu deletes p
}

void Matrix_in::attach (Window& win) // attach all in_boxes
{
    for (int i = 0; i < in_boxes.size(); ++i)
        win.attach(in_boxes[i]);
    own = &win;
}

void Matrix_in::show ()
{
    for (int i = 0; i < in_boxes.size(); ++i)
        in_boxes[i].show();
}
void Matrix_in::hide ()
{
    for (int i = 0; i < in_boxes.size(); ++i)
        in_boxes[i].hide();
}

Matrix Matrix_in::read_matrix() // read matrix from in_boxes
{
    std::vector<long double> vec;
    for(int j = 0; j < this->count_row; ++j)
        for(int i = 0; i < this->count_column; ++i)
        {
            std::stringstream ss;
            ss << in_boxes[i + j * this->count_row].get_string(); // put string number from inbox to stringstream
            long double num = 0;
            ss >> num;
            vec.push_back(num);
        }
    return Matrix {vec, this->count_row, this->count_column};
}
