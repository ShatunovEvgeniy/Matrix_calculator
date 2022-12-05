#include "matrix.h"
#include "row.h"
#include "column.h"
#include "vector.h"
#include "sqr_matrix.h"
#include "Calc_window.h"

#include <iostream>

using namespace std;
using namespace Graph_lib;

int main()
{
    try
    {
        vector<long double> v1{1, 2, 3, 4, 5, 6, 7, 8};
        Column x{v1};
        cout << x;
        Row y = x.T();
        cout << y;
//        Matrix x{2, 3};
        vector<vector<long double>> v{{1.2, 2, 3, 6}, {4, 5, 6, 7}, {8, 9, 10, 11}};
        Matrix z{v};
        long double p = (z[0][0]);
        cout << p << endl;
//        y = y.T();
//        cout << y;
//        Matrix z{2, 3, 5};
//        cout << z;
//        vector<long double> v1{1, 2, 3, 4, 5, 6, 7, 8};
//        Matrix o{v1, 2, 4};
//        Matrix m{v};
//        m = y * 3;
//        cout << m;
//        m += y;
//        cout << m;
//        m = m + y;
//        cout << m;

//        vector<long double> p {1, 2, 3};
//        Vectors v2{p};
//        cout << v2[1] << endl;

//        vector<vector<long double>> b {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
//        Sqr_matrix k{b};
//        cout << k;
//        cout << k.det() << endl;
//        Sqr_matrix l = k.diagonalization();
//        cout << l;
//        k = k.triangle();
//        cout << k;

//        Calc_window winMy = {Point{100, 100}, 1200, 600, "Calc_window"};

//        Graph_lib::gui_main();

    }

    catch(runtime_error e)
    {
        cerr << e.what() << endl;
    }
}
