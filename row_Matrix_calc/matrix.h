#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include <vector>
#include <iostream>

class Column;
class Row;

class Matrix
{
public:
    Matrix() = delete;
    Matrix(const int n, const int m); // empty matrix
    Matrix(const vector<vector<long double>>& num);
    Matrix(int n, int m, long double value); // matrix with same numbers

    Matrix operator+ (const Matrix& mat); // sum of 2 matrixes
    void operator+= (const Matrix& mat); // sum of 2 matrixes

    Matrix operator- (const Matrix& mat); // difference of 2 matrixes
    void operator-= (const Matrix& mat); // difference of 2 matrixes

    Matrix operator* (const Matrix& mat); // product of 2 matrixes
    void operator*= (const Matrix& mat); // product of 2 matrixes

    Matrix operator* (const double& number); // product of every numbers of a matrix and a number
    void operator*= (const double& number); // product of every numbers of a matrix and a number

    Matrix operator/ (const double& number); // qoutient of every numbers of a matrix and a number
    void operator/= (const double& number); // quotient of every numbers of a matrix and a number

    Row operator[] (const int index); // take a row of the matrix

    vector<long double> get_num();
    int get_width();
    int get_length();

    void zeros();

protected:
    Matrix(const vector<long double>& num, int n, int m); // for columns and rows
    vector<long double> numbers;
    int length{0};
    int width{0};
};

ostream& operator<< (ostream& os, Matrix& mat); // to print a matrix in the console
Matrix operator* (const Column& c, const Row& r);

struct Impossible_operation{}; // for errors with impossible operations
struct Bad_value{}; // impossible values for intializations

#endif // MATRIX_H

