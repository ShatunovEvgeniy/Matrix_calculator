#include "Calc_window.h"

using namespace Graph_lib;

Calc_window::Calc_window(Point xy, int w, int h, const std::string& title) // the top left corner, width, length, title
    : Simple_window{xy, w, h, title}

    , general_left_menu{Point{ind, y_max() - 3 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gl"}
    , general_right_menu{Point{x_max() - ind - simple_work_place, y_max() - 3 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gr"}

    , private_left_menu{Point{ind, y_max() - 5 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pl"}
    , private_right_menu{Point{x_max() - ind - simple_work_place, y_max() - 5 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_pr"}

    , middle_left_menu{Point{x_max() / 2 - simple_work_place / btn_count, ind}, simple_work_place / btn_count, 2 * ind, Menu::vertical,"Buttons_ml"}
    , middle_right_menu{Point{x_max() / 2, ind}, simple_work_place / btn_count, 2 * ind, Menu::vertical,"Buttons_mr"}


    , left_save_btn{Point{ind + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Save", save_left}
    , left_columns{Point{ind + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , left_rows{Point{ind + length_top_inbox*3/2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

    , right_save_btn{Point{ind + simple_work_place * 2 + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Save", save_right}
    , right_columns{Point{ind + simple_work_place * 2 + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , right_rows{Point{ind + simple_work_place * 2 + length_top_inbox * 3 / 2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

{
    left_matrix_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 7, 3, 3};   // last 2 args are counts of rows and columns (3 X 3 by default)
    right_matrix_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 7, 3, 3}; // last 2 args are counts of rows and columns (3 X 3 by default)

    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Determ", cb_quit));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Ones", cb_quit));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    attach (general_left_menu);

    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Determ", cb_quit));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Ones", cb_quit));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    attach (general_right_menu);


    private_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Determ", cb_quit));
    private_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Ones", cb_quit));
    attach (private_left_menu);

    private_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    private_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Zeros", cb_quit));
    attach (private_right_menu);


    middle_left_menu.attach(new Button(Point{0, 0}, 0, 0, "+", cb_quit));
    middle_left_menu.attach(new Button(Point{0, 0}, 0, 0, "-", cb_quit));
    middle_left_menu.attach(new Button(Point{0, 0}, 0, 0, "*", cb_quit));
    attach (middle_left_menu);

    middle_right_menu.attach(new Button(Point{0, 0}, 0, 0, "[ x ]", cb_quit));
    middle_right_menu.attach(new Button(Point{0, 0}, 0, 0, "( * )", cb_quit));
    attach (middle_right_menu);


    attach (left_save_btn);
    attach (left_columns);
    attach (left_rows);

    attach (right_save_btn);
    attach (right_columns);
    attach (right_rows);

    (*left_matrix_in).attach(*this);
    (*right_matrix_in).attach(*this);
}

Calc_window::~Calc_window()
{
    delete left_matrix_in;
    delete right_matrix_in;
}

void Calc_window::save_left(Address, Address widget) // get value of left_column and left_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).in_left_col_row();
}

void Calc_window::save_right(Address, Address widget) // get value of right_column and right_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).in_right_col_row();
}

void Calc_window::cb_quit(Address, Address widget) // quit button
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).quit();
}

void Calc_window::in_left_col_row() // get count of columns and rows
{
    int col_count = left_columns.get_int(); // count of columns
    int row_count = left_rows.get_int(); // count of rows

    // std::cout << '(' << x << ',' << y << ')';
    detach(*left_matrix_in); // detach old matrix
    delete left_matrix_in;

    left_matrix_in = new Matrix_in {Point{ ind, 2 * ind }, (simple_work_place), (y_max() - 7 * ind), col_count, row_count}; // buttons = 5 indent, edges = 2 indent

    (*left_matrix_in).attach(*this); // attach new matrix
    redraw();
}

void Calc_window::in_right_col_row() // get count of columns and rows
{
    int col_count = right_columns.get_int(); // count of columns
    int row_count = right_rows.get_int(); // count of rows

    // std::cout << '(' << x << ',' << y << ')';
    detach(*right_matrix_in); // detach old matrix
    delete right_matrix_in;

    right_matrix_in = new Matrix_in { Point{ ind + simple_work_place * 2, 2 * ind}, (simple_work_place), (y_max() - 7 * ind), col_count, row_count}; // buttons = 5 indent, edges = 2 indent

    (*right_matrix_in).attach(*this); // attach new matrix
    redraw();
}
