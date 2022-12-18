#include "Calc_window.h"
#include "Matrix_out.h"
#include "../Logic/matrix.h"
#include <sstream>

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
    , save_btn{Point{x_max() / 2 - simple_work_place / btn_count / 2, y_max() - 4 * ind}, simple_work_place / btn_count, 2 * ind, "Save", cb_save_file}


    , left_make_btn{Point{ind + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", make_left}
    , left_columns{Point{ind + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , left_rows{Point{ind + length_top_inbox*3/2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

    , right_make_btn{Point{ind + simple_work_place * 2 + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", make_right}
    , right_columns{Point{ind + simple_work_place * 2 + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Сolumn:"}
    , right_rows{Point{ind + simple_work_place * 2 + length_top_inbox * 3 / 2, ind}, simple_work_place / 3 / 2, ind, "Row:"}

{
    size_range (w, h, w, h);      // control size window

    left_matrix_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3};   // last 2 args are counts of rows and columns (3 X 3 by default)
    right_matrix_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3}; // last 2 args are counts of rows and columns (3 X 3 by default)

    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Transpose", cb_left_trans));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_left_mult_num));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_left_del_num));
    attach (general_left_menu);

    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Transpose", cb_right_trans));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_right_mult_num));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_right_del_num));
    attach (general_right_menu);

    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Triangulating", cb_left_triangle));
    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Diagonalization", cb_left_diagonal));
    private_left_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Inverse", cb_left_inverse));
    attach (private_left_1_menu);

    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Triangulating", cb_right_triangle));
    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Diagonalization", cb_right_diagonal));
    private_right_1_menu.attach(new Button(Point{0, 0}, 0, 0, "Inverse", cb_right_inverse));
    attach (private_right_1_menu);

    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Determinant", cb_left_determinant));
    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Symmetric", cb_left_symmetric));
    private_left_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Skew symmetric", cb_left_skew_symmtric));
    attach (private_left_2_menu);

    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Determinant", cb_right_determinant));
    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Symmetric", cb_right_symmetric));
    private_right_2_menu.attach(new Button(Point{0, 0}, 0, 0, "Skew symmetric", cb_right_skew_symmtric));
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

void Calc_window::cb_save_file(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).save_file();
}

void Calc_window::cb_quit(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).quit();
}


void Calc_window::cb_left_trans(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_trans();
}
void Calc_window::cb_right_trans(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_trans();
}
void Calc_window::cb_left_mult_num(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_mult_num();
}
void Calc_window::cb_right_mult_num(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_mult_num();
}
void Calc_window::cb_left_del_num(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_del_num();
}
void Calc_window::cb_right_del_num(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_del_num();
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

void Calc_window::cb_left_triangle(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_triangle();
}
void Calc_window::cb_right_triangle(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_triangle();
}
void Calc_window::cb_left_diagonal(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_diagonal();
}
void Calc_window::cb_right_diagonal(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_diagonal();
}
void Calc_window::cb_left_inverse(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_inverse();
}
void Calc_window::cb_right_inverse(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_inverse();
}
void Calc_window::cb_left_determinant(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_determinant();
}
void Calc_window::cb_right_determinant(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_determinant();
}
void Calc_window::cb_left_symmetric(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_symmetric();
}
void Calc_window::cb_right_symmetric(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_symmetric();
}
void Calc_window::cb_left_skew_symmtric(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).left_skew_symmtric();
}
void Calc_window::cb_right_skew_symmtric(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Calc_window&>(btn.window()).right_skew_symmtric();
}


void Calc_window::save_file()
{
    input_file.get_string();
    output_file.get_string();
}


void Calc_window::left_trans()
{
    if(check_matrix(left_matrix_in))
    {
        Matrix left_matrix{left_matrix_in->read_matrix()};
        answer(left_matrix.T(), "Transpose");
    }
}
void Calc_window::right_trans()
{
    if(check_matrix(right_matrix_in))
    {
        Matrix right_matrix{right_matrix_in->read_matrix()};
        answer(right_matrix.T(), "Transpose");
    }
}
void Calc_window::left_mult_num()
{
    if(check_matrix(left_matrix_in))
    {
        Matrix left_matrix{left_matrix_in->read_matrix()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        answer(left_matrix * num, "Multiplication by number");
    }
}
void Calc_window::right_mult_num()
{
    if(check_matrix(right_matrix_in))
    {
        Matrix right_matrix{right_matrix_in->read_matrix()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        answer(right_matrix * num, "Multiplication by number");
    }
}
void Calc_window::left_del_num()
{
    if(check_matrix(left_matrix_in)){
        Matrix left_matrix{left_matrix_in->read_matrix()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        std::cout << num;
        if (num == 0 || std::isnan(num))
        {
            error_output("Division by zero");
            return;
        }
        answer(left_matrix / num, "Division by number");
    }
}
void Calc_window::right_del_num()
{
    if(check_matrix(right_matrix_in)){
        Matrix right_matrix{right_matrix_in->read_matrix()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        std::cout << num;
        if (num == 0 || std::isnan(num))
        {
            error_output("Division by zero");
            return;
        }
        answer(right_matrix / num, "Division by number");
    }
}

void Calc_window::plus() // matrix sum
{
    if(check_matrix(left_matrix_in) && check_matrix(right_matrix_in))
    {
        Matrix left_matrix{left_matrix_in->read_matrix()};
        Matrix right_matrix{right_matrix_in->read_matrix()};
        if(left_matrix.get_rows_count() == right_matrix.get_rows_count() && left_matrix.get_columns_count() == right_matrix.get_columns_count())
            answer(left_matrix + right_matrix, "Sum of matrices");
        else
            error_output("These matrices cannot be summed up");
    }
}
void Calc_window::minus() // matrix difference
{
    if(check_matrix(left_matrix_in) && check_matrix(right_matrix_in))
    {
        Matrix left_matrix{left_matrix_in->read_matrix()};
        Matrix right_matrix{right_matrix_in->read_matrix()};
        if(left_matrix.get_rows_count() == right_matrix.get_rows_count() && left_matrix.get_columns_count() == right_matrix.get_columns_count())
            answer(left_matrix - right_matrix, "Difference of matrices");
        else
            error_output("These matrices cannot be deducted");
    }
}
void Calc_window::mult() // matrix multiplication
{
    if(check_matrix(left_matrix_in) && check_matrix(right_matrix_in))
    {
        Matrix left_matrix{left_matrix_in->read_matrix()};
        Matrix right_matrix{right_matrix_in->read_matrix()};
        if(left_matrix.get_columns_count() == right_matrix.get_rows_count())
            answer(left_matrix * right_matrix, "Product of matrices");
        else
          error_output("These matrices cannot be multiplied");
    }
}

void Calc_window::left_triangle()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        answer(Matrix(sqr.triangle()), "Triangulating");
    }
}
void Calc_window::right_triangle()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer(Matrix(sqr.triangle()), "Triangulating");
    }
}
void Calc_window::left_diagonal()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        answer(sqr.diagonalization(), "Diagonalization");
    }
}
void Calc_window::right_diagonal()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer(sqr.diagonalization(), "Diagonalization");
    }
}
void Calc_window::left_inverse()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        if (sqr.det() != 0)
            answer(sqr.inverse(), "Inverse matrix");
        else
            error_output("The given matrix does not have an inverse (determinant = 0)");
    }
}
void Calc_window::right_inverse()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer(sqr.inverse(), "Inverse matrix");
    }
}

void Calc_window::left_determinant()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        answer_num(sqr.det(), "Determinant");
    }
}
void Calc_window::right_determinant()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer_num(sqr.det(), "Determinant");
    }
}
void Calc_window::left_symmetric()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        answer(sqr.symmetric(), "Symmetric matrix");
    }
}
void Calc_window::right_symmetric()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer(sqr.symmetric(), "Symmetric matrix");
    }
}
void Calc_window::left_skew_symmtric()
{
    if(check_matrix(left_matrix_in))
    {
        Sqr_matrix sqr{left_matrix_in->read_sqr_matrix()};
        answer(sqr.skew_symmetric(), "Scew-symmetric matrix");
    }
}
void Calc_window::right_skew_symmtric()
{
    if(check_matrix(right_matrix_in))
    {
        Sqr_matrix sqr{right_matrix_in->read_sqr_matrix()};
        answer(sqr.skew_symmetric(), "Scew-symmetric matrix");
    }
}

// Other methods

bool Calc_window::check_matrix(Matrix_in* matrix_in){
    try
    {
        Matrix{matrix_in->read_matrix()};
    }
    catch (std::string e)
    {
        error_output(e);
        return false;
    }
    return true;
}

void Calc_window::answer(Matrix matrix, std::string title) // print answer
{
    Simple_window win{Point{100, 100}, 600, 300, title};
    Matrix_out matrix_out{Point{0, 0}, 530, 300, matrix};
    matrix_out.attach(win);
    matrix_out.put();
    win.wait_for_button();
}

void Calc_window::answer_num(long double ans, std::string title)
{
    Simple_window win{Point{100, 100}, 600, 300, title};
    Out_box out_box{Point{0, 0}, 530, 300, ""};
    win.attach(out_box);
    std::stringstream s;
    s << ans;
    out_box.put(s.str());
    win.wait_for_button();
}

void Calc_window::in_left_col_row() // get count of columns and rows
{
    detach(*left_matrix_in); // detach old matrix
    delete left_matrix_in;
    bool flag = true;                                        // if true, then it means a normal matrix
    std::string col_string = left_columns.get_string(); // count of columns
    std::string row_string = left_rows.get_string(); // count of rows
    for (int i; i < (int)col_string.size() ; ++i)
    {
        if (std::isnan(col_string[i]) || col_string[i] < '0' || col_string[i] > '9')
        {
            error_output("Set the dimensions of the matrix as natural numbers");
            flag = false;
            break;
        }
    }
    if (flag)
    {
        for (int i; i < (int)row_string.size() ; ++i)
        {
            if (std::isnan(row_string[i]) || row_string[i] < '0' || row_string[i] > '9')
            {
                error_output("Set the dimensions of the matrix as natural numbers");
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        int col_count{-1};
        int row_count{-1};
        std::stringstream s;
        std::stringstream ss;
        s << col_string;
        s >> col_count;
        ss << row_string;
        ss >> row_count;
        if (col_count < 1 or row_count < 1)
        {
            error_output("Set the dimensions of the matrix as natural numbers");
            flag = false;
        }
        else if (col_count > 10 or row_count > 10)
        {
            error_output("A lot of matrix cells, use the input via file");
            flag = false;
        }
        else
        {
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
        }
    }
    if(!flag)
    {
        private_left_1_menu.show();
        private_left_2_menu.show();
        left_matrix_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3};
    }
    (*left_matrix_in).attach(*this); // attach new matrix
    redraw();
}

void Calc_window::in_right_col_row() // get count of columns and rows
{
    detach(*right_matrix_in); // detach old matrix
    delete right_matrix_in;
    bool flag = true;                                        // if true, then it means a normal matrix
    std::string col_string = right_columns.get_string(); // count of columns
    std::string row_string = right_rows.get_string(); // count of rows
    for(int i; i < (int)col_string.size() ; ++i)
    {
        if(std::isnan(col_string[i]) || col_string[i] < '0' || col_string[i] > '9')
        {
            error_output("Set the dimensions of the matrix as natural numbers");
            flag = false;
            break;
        }
    }
    if(flag)
    {
        for(int i; i < (int)row_string.size() ; ++i)
        {
            if(std::isnan(row_string[i]) || row_string[i] < '0' || row_string[i] > '9')
            {
                error_output("Set the dimensions of the matrix as nutural numbers");
                flag = false;
                break;
            }
        }
    }
    if(flag)
    {
        int col_count;
        int row_count;
        std::stringstream s;
        std::stringstream ss;
        s << col_string;
        s >> col_count;
        ss << row_string;
        ss >> row_count;
        if( col_count < 1 or row_count < 1)
        {
            error_output("Set the dimensions of the matrix as natural numbers");
            flag = false;
        }
        else if( col_count > 10 or row_count > 10)
        {
            error_output("A lot of matrix cells, use the input via file");
            flag = false;
        }
        else
        {
            if (col_count == row_count)
            {
                private_right_1_menu.show();
                private_right_2_menu.show();
            }
            else
            {
                private_right_1_menu.hide();
                private_right_2_menu.hide();
            }
            right_matrix_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, col_count, row_count};
        }
    }
    if(!flag)
    {
        private_right_1_menu.show();
        private_right_2_menu.show();
        right_matrix_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 3};
    }
    (*right_matrix_in).attach(*this); // attach new matrix
    redraw();
}

void Calc_window::error_output(std::string er_what)
{
    Simple_window win{Point{300, 300}, 700, 300, "Error"};
    Text more{Point{win.x_max() / 2 - 200, win.y_max() / 2}, er_what};
    win.attach(more);
    this->hide();
    win.wait_for_button();
    this->show();
}
