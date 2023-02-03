#include "vector_window.h"

#include "Matrix_out.h"
#include "Calc_window.h"
#include "../Logic/vector.h"
#include "../Logic/matrix.h"
#include "../Files work/streams.h"

#include <sstream>

#include <Graph_lib/Simple_window.h>

using namespace Graph_lib;

/// Constructors
Vector_window::Vector_window(Point xy, int w, int h, const std::string& title) // the top left corner, width, length, title
    : Window{xy, w, h, title}

    , general_left_menu{Point{ind, y_max() - 7 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gl"}
    , general_right_menu{Point{x_max() - ind - simple_work_place, y_max() - 7 * ind}, simple_work_place / btn_count, 2 * ind, Menu::horizontal,"Buttons_gr"}

    , middle_menu{Point{x_max() / 2 - simple_work_place / btn_count / 2, 4* ind}, simple_work_place / btn_count, 2 * ind, Menu::vertical,"Buttons_ml"}

    , default_matrix_menu{Point{x_max() / 2 - simple_work_place / 4, ind}, simple_work_place / 2, 2 * ind, "Use default menu", cb_mat_menu}
    , num_btn{Point{x_max() / 2 - ind, y_max() - 13 * ind}, simple_work_place / 4, 2 * ind, "Input a number"}
    , input_file{Point{x_max() / 2 - simple_work_place / 4, y_max() - 10 * ind}, simple_work_place / 2, 2 * ind, "Input file"}
    , output_file{Point{x_max() / 2 - simple_work_place / 4, y_max() - 7 * ind}, simple_work_place / 2, 2 * ind, "Output file"}
    , save_btn{Point{x_max() / 2 - simple_work_place / btn_count / 2, y_max() - 4 * ind}, simple_work_place / btn_count, 2 * ind, "Save", cb_save_file}


    , left_make_btn{Point{ind + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", cb_make_left}
    , left_dimension{Point{ind + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Dimension:"}

    , right_make_btn{Point{ind + simple_work_place * 2 + length_top_inbox * 2, ind}, simple_work_place / 3, ind, "Make", cb_make_right}
    , right_dimension{Point{ind + simple_work_place * 2 + length_top_inbox / 2, ind}, simple_work_place / 3 / 2, ind, "Dimension:"}

{
    size_range (w, h, w, h);      // control size window

    left_vector_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 1};   // last 2 args are counts of rows and columns (3 X 1 by default)
    right_vector_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 1}; // last 2 args are counts of rows and columns (3 X 1 by default)

    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "Length", cb_left_length));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_left_mult_num));
    general_left_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_left_del_num));
    attach (general_left_menu);

    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "Length", cb_right_length));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "* number", cb_right_mult_num));
    general_right_menu.attach(new Button(Point{0, 0}, 0, 0, "/ number", cb_right_del_num));
    attach (general_right_menu);

    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "+", cb_plus));
    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "-", cb_minus));
    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "*", cb_scalar_mult));
    middle_menu.attach(new Button(Point{0, 0}, 0, 0, "Vec prod", cb_vector_mult));
    attach (middle_menu);

    attach (num_btn);
    attach (input_file);
    attach (output_file);
    attach (save_btn);
    attach (default_matrix_menu);

    attach (left_make_btn);
    attach (left_dimension);

    attach (right_make_btn);
    attach (right_dimension);

    (*left_vector_in).attach(*this);
    (*right_vector_in).attach(*this);
}

/// Destructors
Vector_window::~Vector_window()
{
    delete left_vector_in;
    delete right_vector_in;
}

/// Methods

// Button functions
void Vector_window::cb_make_left(Address, Address widget) // get value of left_column and left_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).in_left_dimension();
}

void Vector_window::cb_make_right(Address, Address widget) // get value of right_column and right_rows
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).in_right_dimension();
}

void Vector_window::cb_save_file(Address, Address widget)
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).save_file();
}

void Vector_window::cb_quit(Address, Address widget) // call quit
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).quit();
}
void Vector_window::cb_mat_menu(Address, Address widget) // call fintion to use default menu
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).matrix_menu();
}

void Vector_window::cb_left_length(Address, Address widget) // call left_length function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).left_length();
}
void Vector_window::cb_right_length(Address, Address widget) // call right_length function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).right_length();
}
void Vector_window::cb_left_mult_num(Address, Address widget) // call left_mul_num function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).left_mult_num();
}
void Vector_window::cb_right_mult_num(Address, Address widget) // call right_mult_num function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).right_mult_num();
}
void Vector_window::cb_left_del_num(Address, Address widget) // call left_del_num function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).left_del_num();
}
void Vector_window::cb_right_del_num(Address, Address widget) // call right_del_num functino
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).right_del_num();
}

void Vector_window::cb_plus(Address, Address widget) // call plus function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).plus();
}
void Vector_window::cb_minus(Address, Address widget) // call minus function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).minus();
}
void Vector_window::cb_scalar_mult(Address, Address widget) // call scalar mult function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).scalar_mult();
}
void Vector_window::cb_vector_mult(Address, Address widget) // call scalar mult function
{
    auto& btn = reference_to<Graph_lib::Button>(widget);
    dynamic_cast<Vector_window&>(btn.window()).vector_mult();
}


void Vector_window::save_file()
{
    std::string in_file (input_file.get_string());
    std::string out_file(output_file.get_string());
    try
    {
        calculate(in_file, out_file);
        error_output("All done");
    }
    catch(std::runtime_error e)
    {
        error_output(e.what());
    }
}

void Vector_window::matrix_menu()
{
    this->hide();
    Calc_window win{Point{100, 100}, 1200, 600, "Calc_window"};
    Graph_lib::gui_main();
}

void Vector_window::left_length()
{
    if(check_vector(left_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        answer_num(left_vector.vec_length(), "Length");
    }
}
void Vector_window::right_length()
{
    if(check_vector(right_vector_in))
    {
        Vectors right_vector{right_vector_in->read_std_vector()};
        answer_num(right_vector.vec_length(), "Length");
    }
}
void Vector_window::left_mult_num()
{
    if(check_vector(left_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        answer(left_vector * num, "Multiplication by number");
    }
}
void Vector_window::right_mult_num()
{
    if(check_vector(right_vector_in))
    {
        Vectors right_vector{right_vector_in->read_std_vector()};
        long double num;
        std::stringstream s;
        s << num_btn.get_string();
        s >> num;
        answer(right_vector * num, "Multiplication by number");
    }
}
void Vector_window::left_del_num()
{
    if(check_vector(left_vector_in)){
        Vectors left_vector{left_vector_in->read_std_vector()};
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
        answer(left_vector / num, "Division by number");
    }
}
void Vector_window::right_del_num()
{
    if(check_vector(right_vector_in)){
        Vectors right_vector{right_vector_in->read_std_vector()};
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
        answer(right_vector / num, "Division by number");
    }
}

void Vector_window::plus() // vector sum
{
    if(check_vector(left_vector_in) && check_vector(right_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        Vectors right_vector{right_vector_in->read_std_vector()};
        if(left_vector.get_rows_count() == right_vector.get_rows_count())
            answer(left_vector + right_vector, "Sum of vectors");
        else
            error_output("These vectors cannot be summed up");
    }
}
void Vector_window::minus() // vector difference
{
    if(check_vector(left_vector_in) && check_vector(right_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        Vectors right_vector{right_vector_in->read_std_vector()};
        if(left_vector.get_rows_count() == right_vector.get_rows_count())
            answer(left_vector - right_vector, "Difference of vectors");
        else
            error_output("These vectors cannot be deducted");
    }
}
void Vector_window::scalar_mult() // scalar multiplication
{
    if(check_vector(left_vector_in) && check_vector(right_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        Vectors right_vector{right_vector_in->read_std_vector()};
        if(left_vector.get_rows_count() == right_vector.get_rows_count() && left_vector.get_rows_count() >= 2 &&  right_vector.get_rows_count() >= 2)
            answer(left_vector * right_vector, "Scalar product of vectors");
        else
          error_output("These vectors cannot be scalar multiplied");
    }
}

void Vector_window::vector_mult() // vector multiplication
{
    if(check_vector(left_vector_in) && check_vector(right_vector_in))
    {
        Vectors left_vector{left_vector_in->read_std_vector()};
        Vectors right_vector{right_vector_in->read_std_vector()};
        if(left_vector.get_rows_count() == right_vector.get_rows_count() && left_vector.get_rows_count() >= 3 &&  right_vector.get_rows_count() >= 3)
            answer(left_vector.vec_prod(right_vector), "Vector product of vectors");
        else
            error_output("These vectors cannot be vector multiplied");
    }
}


// Other methods

bool Vector_window::check_vector(Matrix_in* matrix_in){
    try
    {
        Vectors{matrix_in->read_std_vector()};
    }
    catch (std::string e)
    {
        error_output(e);
        return false;
    }
    return true;
}

void Vector_window::answer(Vectors vector, std::string title) // print answer
{
    Simple_window win{Point{100, 100}, 600, 300, title};
    Matrix_out matrix_out{Point{0, 0}, 530, 300, vector};
    matrix_out.attach(win);
    matrix_out.put();
    win.wait_for_button();
}

void Vector_window::answer_num(long double ans, std::string title)
{
    Simple_window win{Point{100, 100}, 600, 300, title};
    Out_box out_box{Point{0, 0}, 530, 300, ""};
    win.attach(out_box);
    std::stringstream s;
    s << ans;
    out_box.put(s.str());
    win.wait_for_button();
}

void Vector_window::in_left_dimension() // get left dimension
{
    detach(*left_vector_in); // detach old vector
    delete left_vector_in;
    bool flag = true;                                        // if true, then it means a normal vector
    std::string vec_dimension = left_dimension.get_string(); // dimension
    for (int i; i < (int)vec_dimension.size() ; ++i)
    {
        if (std::isnan(vec_dimension[i]) || vec_dimension[i] < '0' || vec_dimension[i] > '9')
        {
            error_output("Set the dimension of the vector as a natural number");
            flag = false;
            break;
        }
    }
    if (flag)
    {
        int dim{-1};
        std::stringstream s;
        s << vec_dimension;
        s >> dim;
        if (dim < 1)
        {
            error_output("Set the dimension of the vector as a natural number");
            flag = false;
        }
        else if (dim > 3)
        {
            error_output("Use vectors with dimensions: 1, 2, 3");
            flag = false;
        }
        else
        {
            if (dim == 1)
            {
            }
            else if (dim == 2)
            {
            }
            else if (dim == 3)
            {
            }
            left_vector_in = new Matrix_in {Point{ ind, 2 * ind }, (simple_work_place), (y_max() - 9 * ind), dim, 1}; // buttons = 5 indent, edges = 2 indent
        }
    }

    if( !flag )
        left_vector_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 1};

    (*left_vector_in).attach(*this); // attach new matrix
    redraw();
}

void Vector_window::in_right_dimension() // get right dimension
{
    detach(*right_vector_in); // detach old vector
    delete right_vector_in;
    bool flag = true;                                        // if true, then it means a normal vector
    std::string vec_dimension = right_dimension.get_string(); // dimension
    for (int i; i < (int)vec_dimension.size() ; ++i)
    {
        if (std::isnan(vec_dimension[i]) || vec_dimension[i] < '0' || vec_dimension[i] > '9')
        {
            error_output("Set the dimension of the vector as a natural number");
            flag = false;
            break;
        }
    }
    if (flag)
    {
        int dim{-1};
        std::stringstream s;
        s << vec_dimension;
        s >> dim;
        if (dim < 1)
        {
            error_output("Set the dimension of the vector as a natural number");
            flag = false;
        }
        else if (dim > 3)
        {
            error_output("Use vectors with dimensions: 1, 2, 3");
            flag = false;
        }
        else
        {
            if (dim == 1)
            {
            }
            else if (dim == 2)
            {
            }
            else if (dim == 3)
            {
            }
            right_vector_in = new Matrix_in {Point{ind + simple_work_place * 2, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 1};
        }
    }

    if( !flag )
        right_vector_in = new Matrix_in {Point{ind, 2 * ind}, simple_work_place, y_max() - ind * 9, 3, 1};

    (*right_vector_in).attach(*this); // attach new matrix
    redraw();
}

void Vector_window::error_output(std::string er_what)
{
    Simple_window win{Point{300, 300}, 700, 300, "Error"};
    Text more{Point{win.x_max() / 2 - 200, win.y_max() / 2}, er_what};
    win.attach(more);
    this->hide();
    win.wait_for_button();
    this->show();
}
