#ifndef CALC_WINDOW_H
#define CALC_WINDOW_H

#include "Matrix_in.h"

#include <Graph_lib/Graph.h>

class Calc_window : public Graph_lib::Window
{
public:
    Calc_window(Graph_lib::Point xy, int w, int h, const std::string& title);
    ~Calc_window();

private:

    static constexpr int ind = 20;  // vertical indent
    static constexpr int btn_count = 3;   // number of buttons at the bottom
    const int simple_work_place = (x_max() - 2 * ind) / 3;  // length of work zone (matixes, central button)
    const int length_top_inbox = simple_work_place / 3; // length between: column / row / save

    Graph_lib::Menu general_left_menu; // left menu for functions for all objects
    Graph_lib::Menu general_right_menu; // right menu for functions for all objects
    Graph_lib::Menu private_left_1_menu; // left menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_right_1_menu; // rigth menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_left_2_menu; // left menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_right_2_menu; // rigth menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu middle_menu; // central menu

    Graph_lib::Button using_vec; // using vector's window
    Graph_lib::Button save_btn;  // save filename
    Graph_lib::In_box num_btn; // to input a number
    Graph_lib::In_box input_file; // to input an input file
    Graph_lib::In_box output_file; // to input an output file

    Graph_lib::Button left_make_btn; // left make button
    Graph_lib::In_box left_columns; // count of left columns
    Graph_lib::In_box left_rows; // count of left rows

    Graph_lib::Button right_make_btn; // right make button
    Graph_lib::In_box right_columns; // count of right columns
    Graph_lib::In_box right_rows; // count of right rows

    Graph_lib::Matrix_in* left_matrix_in = nullptr; // left matrix in
    Graph_lib::Matrix_in* right_matrix_in = nullptr; // right matrix in

    // buttons realization
    static void make_left(Graph_lib::Address, Graph_lib::Address widget); // get value of left_column and left_rows
    static void make_right(Graph_lib::Address, Graph_lib::Address widget); // get value of right_column and right_rows
    static void cb_left_trans(Graph_lib::Address, Graph_lib::Address widet);
    static void cb_right_trans(Graph_lib::Address, Graph_lib::Address widet);
    static void cb_left_mult_num(Graph_lib::Address, Graph_lib::Address widet);
    static void cb_right_mult_num(Graph_lib::Address, Graph_lib::Address widet);
    static void cb_left_del_num(Graph_lib::Address, Graph_lib::Address widet);
    static void cb_right_del_num(Graph_lib::Address, Graph_lib::Address widet);

    static void cb_save_file(Graph_lib::Address, Graph_lib::Address widget);

    static void cb_quit(Graph_lib::Address, Graph_lib::Address widget); // call quit
    static void cb_plus(Graph_lib::Address, Graph_lib::Address widget); // call plus
    static void cb_minus(Graph_lib::Address, Graph_lib::Address widget); // call minus
    static void cb_mult(Graph_lib::Address, Graph_lib::Address widget); // call mult
    static void cb_left_triangle(Graph_lib::Address, Graph_lib::Address widget); //call triangle
    static void cb_right_triangle(Graph_lib::Address, Graph_lib::Address widget); //call triangle
    static void cb_left_diagonal(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_right_diagonal(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_left_inverse(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_right_inverse(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_left_determinant(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_right_determinant(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_left_symmetric(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_right_symmetric(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_left_skew_symmtric(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_right_skew_symmtric(Graph_lib::Address, Graph_lib::Address widget);


    void quit(){ hide(); } // hide window
    void save_file();
    void left_trans();
    void right_trans();
    void left_mult_num();
    void right_mult_num();
    void left_del_num();
    void right_del_num();

    void plus(); // matrix sum
    void minus(); // matrix difference
    void mult(); // matrix multiplication
    void left_triangle();
    void right_triangle();
    void left_diagonal();
    void right_diagonal();
    void left_inverse();
    void right_inverse();
    void left_determinant();
    void right_determinant();
    void left_symmetric();
    void right_symmetric();
    void left_skew_symmtric();
    void right_skew_symmtric();


    void in_left_col_row(); // get count of columns and rows
    void in_right_col_row(); // get count of columns and rows

    bool check_matrix(Graph_lib::Matrix_in* matrix_in);
    void answer(Matrix matrix); // print answer
    void answer_num(long double ans); //print number answer
    void error_output(std::string ass);
};

#endif // CALC_WINDOW_H
