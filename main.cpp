#include <iostream>

using namespace std;

#include "matrix.h"
#include "row.h"
#include "sqr_matrix.h"

int main()
{
    /*vector <vector <long double>> num{{1,2,3, 4}, {4,5,6, 9}, {7,8,9, 11}};
    Matrix mat1{num};
    cout << mat1;
    vector <vector <long double>> num1{{1,2,3,4}, {4,5,6,7}, {7,8,9,10}};
    Matrix mat2{num1};
    cout << mat2;
    Matrix x = (mat1 - mat2);
    cout << x;
    Matrix mat3{4, 3, 9};
    cout << mat3;
    mat3.zeros();
    cout << mat3;
    mat2+= mat1;
    */
    vector<vector<long double>> v {{1,2,3}, {4,5,6}, {7,8,9}};
    Sqr_matrix m{v};
    m = m.T();
    cout << m;
}
