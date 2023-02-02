#ifndef VECTOR_WINDOW_H
#define VECTOR_WINDOW_H

#include "Matrix_in.h"

#include <Graph_lib/Graph.h>

class Vector_window : public Graph_lib::Window
{
public:
    Vector_window(Graph_lib::Point xy, int w, int h, const std::string& title);
    ~Vector_window();

private:

    static constexpr int ind = 20;  // vertical indent
    static constexpr int btn_count = 3;   // number of buttons at the bottom
    const int simple_work_place = (x_max() - 2 * ind) / 3;  // length of work zone (matrixes, central button)
    const int length_top_inbox = simple_work_place / 3; // length between: column / row / save

    Graph_lib::Menu general_left_menu; // left menu for all vectors functions
    Graph_lib::Menu general_right_menu; // right menu for all vectors functions
    Graph_lib::Menu middle_menu; // central menu

    Graph_lib::Button default_matrix_menu; // using default menu
    Graph_lib::Button save_btn;  // save filename
    Graph_lib::In_box num_btn; // to input a number
    Graph_lib::In_box input_file; // to input an input file
    Graph_lib::In_box output_file; // to input an output file

    Graph_lib::Button left_make_btn; // left make button
    Graph_lib::In_box left_dimension; // dimension of left vector

    Graph_lib::Button right_make_btn; // right make button
    Graph_lib::In_box right_dimension; // dimension of right columns

    Graph_lib::Matrix_in* left_vector_in = nullptr; // left vector in
    Graph_lib::Matrix_in* right_vector_in = nullptr; // right vector in

    // buttons realization
    static void cb_make_left(Graph_lib::Address, Graph_lib::Address widget); // get value of left vector's dimension
    static void cb_make_right(Graph_lib::Address, Graph_lib::Address widget); // get value of right vector's dimension
    static void cb_left_length(Graph_lib::Address, Graph_lib::Address widet); // get left vector's length
    static void cb_right_length(Graph_lib::Address, Graph_lib::Address widet); // get right vector's length
    static void cb_left_mult_num(Graph_lib::Address, Graph_lib::Address widet); // multipliciation of a number and a left vector
    static void cb_right_mult_num(Graph_lib::Address, Graph_lib::Address widet); // multipliciation of a number and a right vector
    static void cb_left_del_num(Graph_lib::Address, Graph_lib::Address widet); // division of a number and a left vector
    static void cb_right_del_num(Graph_lib::Address, Graph_lib::Address widet); // division of a number and a right vector

    static void cb_save_file(Graph_lib::Address, Graph_lib::Address widget); // call save_file funciton
    static void cb_mat_menu(Graph_lib::Address, Graph_lib::Address widget); // call using defalut menu function

    static void cb_quit(Graph_lib::Address, Graph_lib::Address widget); // call quit functions
    static void cb_plus(Graph_lib::Address, Graph_lib::Address widget); // call plus function
    static void cb_minus(Graph_lib::Address, Graph_lib::Address widget); // call minus function
    static void cb_scalar_mult(Graph_lib::Address, Graph_lib::Address widget); // call scalar_mult function
    static void cb_vector_mult(Graph_lib::Address, Graph_lib::Address widget); // call vector_mult function


    void quit(){ hide(); } // hide window
    void save_file();
    void matrix_menu();
    void left_length();
    void right_length();
    void left_mult_num();
    void right_mult_num();
    void left_del_num();
    void right_del_num();

    void plus(); // matrix sum
    void minus(); // matrix difference
    void scalar_mult(); // matrix scalar multiplication
    void vector_mult(); // matrix vector multiplication

    void in_left_dimension(); // get left dimension
    void in_right_dimension(); // get right dimension

    bool check_vector(Graph_lib::Matrix_in* matrix_in); // check entered vector
    void answer(Vectors vector, std::string); // print answer
    void answer_num(long double ans, std::string); //print number answer
    void error_output(std::string er_what);
};

#endif // VECTOR_WINDOW_H
