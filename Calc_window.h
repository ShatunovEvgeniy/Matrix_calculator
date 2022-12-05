#ifndef CALC_WINDOW_H
#define CALC_WINDOW_H

#include <iostream>
#include "Window.h"                    //<Graph_lib/Window.h>
#include "Graph.h"                     //<Graph_lib/Graph.h>
#include "Matrix_in.h"
#include "Matrix_out.h"

struct Calc_window : Graph_lib::Window
{
    Calc_window(Graph_lib::Point xy, int w, int h, const std::string& title);
    ~Calc_window();

    static constexpr int ind = 20;  // vertical indent
    static constexpr int btn_count = 3;   // number of buttons at the bottom
    const int simple_work_place = (x_max() - 2 * ind) / 3;  // length of work zone (matixes, central button)                 ///!!!!! expr
    const int length_top_inbox = simple_work_place / 3; // length between: column / row / save                          ///!!!!! expr

    Graph_lib::Menu general_left_menu; // left menu for functions for all objects
    Graph_lib::Menu general_right_menu; // right menu for functions for all objects
    Graph_lib::Menu private_left_1_menu; // left menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_right_1_menu; // rigth menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_left_2_menu; // left menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_right_2_menu; // rigth menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu middle_menu; // central menu

    Graph_lib::Button using_vec; //using vector's window
    Graph_lib::In_box num_btn;
    Graph_lib::In_box input_file;
    Graph_lib::In_box output_file;
    Graph_lib::Button save_btn;  //save filename

    Graph_lib::Button left_make_btn; // left make button
    Graph_lib::In_box left_columns; // count of left columns
    Graph_lib::In_box left_rows; // count of left rows

    Graph_lib::Button right_make_btn; // right make button
    Graph_lib::In_box right_columns; // count of right columns
    Graph_lib::In_box right_rows; // count of right rows

    Graph_lib::Matrix_in* left_matrix_in = nullptr; // left matrix in
    Graph_lib::Matrix_in* right_matrix_in = nullptr; // right matrix in


private:

   // buttons realization
    static void make_left(Graph_lib::Address, Graph_lib::Address widget); // get value of left_column and left_rows
    static void make_right(Graph_lib::Address, Graph_lib::Address widget); // get value of right_column and right_rows
    static void cb_btn(Graph_lib::Address, Graph_lib::Address widget); // reference button
    static void cb_quit(Graph_lib::Address, Graph_lib::Address widget); // quit button
    static void cb_plus(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_minus(Graph_lib::Address, Graph_lib::Address widget);
    static void cb_mult(Graph_lib::Address, Graph_lib::Address widget);

    void reference();
    void quit(){ hide(); } // hide window
    void plus();
    void minus();
    void mult();


    void in_left_col_row(); // get count of columns and rows
    void in_right_col_row(); // get count of columns and rows

    void answer(Matrix matrix);
};

#endif // CALC_WINDOW_H
