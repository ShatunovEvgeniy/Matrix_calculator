#include "matrix.h"
#include "row.h"
#include "column.h"
#include "vector.h"
#include "sqr_matrix.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        Matrix x{2, 3};
        vector<vector<long double>> v{{1, 2, 3, 6}, {4, 5, 6, 7}, {8, 9, 10, 11}};
        Matrix y{v};
        Matrix z{2, 3, 5};
        vector<long double> v1{1, 2, 3, 4, 5, 6, 7, 8};
        Matrix o{v1, 2, 4};

        Matrix m{v};
        m = y * 3;
        cout << m;
        m += y;
        cout << m;
        m = m + y;
        cout << m;

        vector<long double> p {1, 2, 3};
        Vectors v2{p};
        cout << v2[1] << endl;
    }

    catch(runtime_error e)
    {
        cerr << e.what() << endl;
    }
}
