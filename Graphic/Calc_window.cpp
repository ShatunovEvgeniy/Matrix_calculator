#include "Calc_window.h"
#include "Matrix_out.h"
#include "../Logic/matrix.h"

#include <Graph_lib/Simple_window.h>

using namespace Graph_lib;

/// Constructors
Calc_window::Calc_window(Point xy, int w, int h, const std::string& title) // the top left corner, width, length, title
    : Window{xy, w, h, title}

    , general_left_menu{Point{ind, y_max() - 7 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gl"}
    , general_right_menu{Point{x_max() - ind - simple_work_place, y_max() - 7 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gr"}

    , private_left_1_menu{Point{ind, y_max() - 5 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pl"}
    , private_right_1_menu{Point{x_max() - ind - simple_work_place, y_max() - 5 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pr"}

    , private_left_2_menu{Point{ind, y_max() - 3 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pl"}
    , private_right_2_menu{Point{x_max() - ind - simple_work_place, y_max() - 3 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pr"}

    , middle_menu{Point{x_max() / 2 - simple_work_place / btn_count / 2, 4* ind}, simple_work_place / btn_count, 2 * ind, Menu::vertical,"Buttons_ml"}

    , using_vec{Point{x_max() / 2 - simple_work_place / 4, ind}, simple_work_place / 2, 2 * ind, "Using vector", cb_quit}
    , num_btn{Point{x_max() / 2 - ind, y_max() - 13 * ind}, simple_work_place / 4, 2 * ind, "Input a number"}
    , input_file{Point{x_max() / 2 - simple_work_place / 4, y_max() - 10 * ind}, simple_work_place / 2, 2 * ind, "Input file"}
    , output_file{Point{x_max() / 2 - simple_work_place / 4, y_max() - 7 * ind}, simple_work_place / 2, 2 * ind, "Output file"}
    , save_btn{Point{x_max() / 2 - simple_work_place / btn_count / 2, y_max() - 4 * ind}, simple_work_place / btn_count, 2 * ind, "Save", cb_quit}


    , left_make_btn{Point{ind + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", make_left}
    , left_columns{Point{ind + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , left_rows{Point{ind + length_top_inbox*3/2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

    , right_make_btn{Point{ind + simple_work_place * 2 + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", make_right}
    , right_columns{Point{ind + simple_work_place * 2 + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , right_rows{Point{ind + simple_work_place * 2 + length_top_inbox * 3 / 2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

{
    left_matrix_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3};   // last 2 args are counts of rows and columns (3 X 3 by default)
    right_matrix_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3}; // last 2 args are counts of rows and columns (3 X 3 by default)

    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Transpose", cb_btn));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_quit));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_quit));
    attach (general_left_menu);

    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Transpose", cb_btn));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_quit));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_quit));
    attach (general_right_menu);

    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Triangulating", cb_quit));
    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Diagonalization", cb_quit));
    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Inverse", cb_quit));
    attach (private_left_1_menu);

    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Triangulating", cb_quit));
    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Diagonalization", cb_quit));
    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Inverse", cb_quit));
    attach (private_right_1_menu);

    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Determinant", cb_quit));
    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Symmetric", cb_quit));
    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Skew symmetric", cb_quit));
    attach (private_left_2_menu);

    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Determinant", cb_quit));
    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Symmetricr", cb_quit));
    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Skew symmetric", cb_quit));
    attach (private_right_2_menu);

    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "+", cb_plus));
    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "-", cb_minus));
    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "*", cb_mult));
    attach (middle_menu);

    attach (using_vec);
    attach (num_btn);
    attach (input_file);
    attach (output_file);
    attach (save_btn);

    attach (left_make_btn);
    attach (left_columns);
    attach (left_rows);

    attach (right_make_btn);
    attach (right_columns);
    attach (right_rows);

    (*left_matrix_in).attach(*this);
    (*right_matrix_in).attach(*this);
}

/// Destructors
Calc_window::~Calc_window()
{
    delete left_matrix_in;
    delete right_matrix_in;
}

/// Methods

// Button functions
void Calc_window::make_left(Address, Address widget) // get value of left_column and left_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).in_left_col_row();
}

void Calc_window::make_right(Address, Address widget) // get value of right_column and right_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).in_right_col_row();
}

void Calc_window::cb_btn(Address, Address widget) // call reference
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).reference();
}

void Calc_window::cb_quit(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).quit();
}

void Calc_window::cb_plus(Address, Address widget) // call plus
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).plus();
}

void Calc_window::cb_minus(Address, Address widget) // call minus
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).minus();
}

void Calc_window::cb_mult(Address, Address widget) // call mult
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).mult();
}

void Calc_window::plus() // matrix sum
{
    Matrix left_matrix{left_matrix_in->read_matrix()};
    Matrix right_matrix{right_matrix_in->read_matrix()};

    answer(left_matrix + right_matrix);
}
void Calc_window::minus() // matrix difference
{
    Matrix left_matrix{left_matrix_in->read_matrix()};
    Matrix right_matrix{right_matrix_in->read_matrix()};

    answer(left_matrix - right_matrix);
}

void Calc_window::mult() // matrix multiplication
{
    Matrix left_matrix{left_matrix_in->read_matrix()};
    Matrix right_matrix{right_matrix_in->read_matrix()};

    answer(left_matrix * right_matrix);
}

void Calc_window::reference() // call void answer answer
{
    Matrix matrix{left_matrix_in->read_matrix()};

    answer(matrix);
}

// Other methods
void Calc_window::answer(Matrix matrix) // print answer
{
    Simple_window win{Point{100, 100}, 600, 300, "Matrix_out_window"};

    Matrix_out matrix_out{Point{100, 100}, 400, 200, matrix};
    matrix_out.attach(win);
    matrix_out.put();
    win.wait_for_button();
}

void Calc_window::in_left_col_row() // get count of columns and rows
{
    int col_count = left_columns.get_int(); // count of columns
    int row_count = left_rows.get_int(); // count of rows

    detach(*left_matrix_in); // detach old matrix
    delete left_matrix_in;

    if (col_count == row_count)
    {
        private_left_1_menu.show();
        private_left_2_menu.show();
    }
    else
    {
        private_left_1_menu.hide();
        private_left_2_menu.hide();
    }

    left_matrix_in = new Matrix_in {Point{ ind, 2 * ind }, (simple_work_place), (y_max() - 9 * ind), col_count, row_count}; // buttons = 5 indent, edges = 2 indent

    (*left_matrix_in).attach(*this); // attach new matrix
    redraw();
}

void Calc_window::in_right_col_row() // get count of columns and rows
{
    int col_count = right_columns.get_int(); // count of columns
    int row_count = right_rows.get_int(); // count of rows

    detach(*right_matrix_in); // detach old matrix
    delete right_matrix_in;

    if( col_count == row_count)
    {
        private_right_1_menu.show();
        private_right_2_menu.show();
    }
    else
    {
        private_right_1_menu.hide();
        private_right_2_menu.hide();
    }

    right_matrix_in = new Matrix_in { Point{ ind + simple_work_place * 2, 2 * ind}, (simple_work_place), (y_max() - 9 * ind), col_count, row_count}; // buttons = 5 indent, edges = 2 indent

    (*right_matrix_in).attach(*this); // attach new matrix
    redraw();
}
