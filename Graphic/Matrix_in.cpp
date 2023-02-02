#include "iostream"

#include "Matrix_in.h"
#include <sstream>

#include <vector>

using namespace Graph_lib;

/// Constructors
Matrix_in::Matrix_in(Point xy, int w, int h, int count_rows, int count_columns)
    : Widget{ xy, w, h, "Matrix_in", nullptr}, count_row{count_rows}, count_column{count_columns}
{
    for(int j = 0; j < count_columns; ++j)
        for(int i = 0; i < count_rows; ++i)
            in_boxes.push_back(new In_box{Point{xy.x + w / count_rows * i, xy.y + h / count_columns * j}, w / count_rows, h / count_columns, ""}); // last arg is the same to make a sqr
}

/// Methods
int Matrix_in::attach(In_box& b)
{
    b.width = width;
    b.height = height;
    in_boxes.push_back (b);
    return int(in_boxes.size()-1);
}

int Matrix_in::attach (In_box* p)
{ return attach (*p); }

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

std::vector<long double> Matrix_in::read_std_vector() // read vector from in_boxes
{
    std::vector<long double> vec;
    for(int j = 0; j < count_column; ++j)
        for(int i = 0; i < count_row; ++i)
        {
            std::stringstream ss;
            ss << in_boxes[i + j * count_row].get_string(); // put string number from inbox to stringstream
            long double num = 0;

            char first;
            ss >> first;
            char x = '0';
            char y = '9';
            if((std::isnan(first)) || !((first >= '0') && (first <= '9')))
            {
                std::string str{ "Please rewtire the matrix. Matrix can contain only numbers" };
                throw str;
            }
            ss.putback(first);

            ss >> num;
            std::string ost;
            ss >> ost;
            std::cout << ost;
            if(ost != ""){
                if(ost[0] == ','){
                    std::string str = "Error: '" + ost + "'  Use '.' for float numbers";
                    throw str;
                }
                else
                {
                    std::string str{ "Unexpected symbol : " + ost };
                    throw str;
                }
            }
            else
                vec.push_back(num);
        }
    return vec;
}

Matrix Matrix_in::read_matrix()
{
    Matrix mat{read_std_vector(), count_row, count_column};
    return mat;
}

Sqr_matrix Matrix_in::read_sqr_matrix()
{
    return Sqr_matrix {read_std_vector()};
}

Row Matrix_in::read_row()
{
    return Row {read_std_vector()};
}

Column Matrix_in::read_column()
{
    return Column {read_std_vector()};
}
