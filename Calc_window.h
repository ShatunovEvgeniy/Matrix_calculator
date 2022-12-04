#ifndef CALC_WINDOW_H
#define CALC_WINDOW_H

#include <iostream>
#include <Graph_lib/Window.h>
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include "Matrix_in.h"

struct Calc_window : Simple_window
{
    Calc_window(Graph_lib::Point xy, int w, int h, const std::string& title);
    ~Calc_window();

    static constexpr int ind = 20;  // vertical indent
    static constexpr int btn_count = 4;   // number of buttons at the bottom
    const int simple_work_place = (x_max() - 2 * ind) / 3;  // length of work zone (matixes, central button)                 ///!!!!! expr
    const int length_top_inbox = simple_work_place / 3; // length between: column / row / save                          ///!!!!! expr

    Graph_lib::Menu general_left_menu; // left menu for functions for all objects
    Graph_lib::Menu general_right_menu; // right menu for functions for all objects
    Graph_lib::Menu private_left_menu; // left menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu private_right_menu; // rigth menu for fuctions for special objects such as sqr_matrix and vector
    Graph_lib::Menu middle_left_menu; // left central menu
    Graph_lib::Menu middle_right_menu; // right central menu

    Graph_lib::Button left_save_btn; // left save button
    Graph_lib::In_box left_columns; // count of left columns
    Graph_lib::In_box left_rows; // count of left rows

    Graph_lib::Button right_save_btn; // right save button
    Graph_lib::In_box right_columns; // count of right columns
    Graph_lib::In_box right_rows; // count of right rows

    Graph_lib::Matrix_in* left_matrix_in = nullptr; // left matrix in
    Graph_lib::Matrix_in* right_matrix_in = nullptr; // right matrix in

private:

   // buttons realization
    static void save_left(Graph_lib::Address, Graph_lib::Address widget); // get value of left_column and left_rows
    static void save_right(Graph_lib::Address, Graph_lib::Address widget); // get value of right_column and right_rows
    static void cb_quit(Graph_lib::Address, Graph_lib::Address widget); // quit button

    void quit(){ hide(); } // hide window

    void in_left_col_row(); // get count of columns and rows
    void in_right_col_row(); // get count of columns and rows
};

#endif // CALC_WINDOW_H
