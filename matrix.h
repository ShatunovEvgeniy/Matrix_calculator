#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include <vector>
#include <iostream>

class Column;
class Row;
class Sqr_matrix;

class Matrix
{
public:
    Matrix() = delete;
    Matrix(const int n, const int m); // empty matrix
    Matrix(const vector<vector<long double>>& num);
    Matrix(int n, int m, long double value); // matrix with same numbers

    Matrix(const vector<long double>& num, int n, int m); // for columns and rows
    Matrix(const Column& c);
    Matrix(const Row& r);
    Matrix(const Sqr_matrix& m);

    Matrix operator+ (const Matrix& mat) const ; // sum of 2 matrixes
    void operator+= (const Matrix& mat); // sum of 2 matrixes

    Matrix operator- (const Matrix& mat) const; // difference of 2 matrixes
    void operator-= (const Matrix& mat); // difference of 2 matrixes

    Matrix operator* (const Matrix& mat) const; // product of 2 matrixes
    void operator*= (const Matrix& mat); // product of 2 matrixes

    Matrix operator* (const double& number) const; // product of every numbers of a matrix and a number
    void operator*= (const double& number); // product of every numbers of a matrix and a number

    Matrix operator/ (const double& number) const; // qoutient of every numbers of a matrix and a number
    void operator/= (const double& number); // quotient of every numbers of a matrix and a number

    Row operator[] (const int index) const; // take a row of the matrix

    virtual vector<long double> get_num() const;
    virtual int get_width() const;
    virtual int get_length() const;

    virtual void zeros();

protected:
    int length{0};
    int width{0};
    vector<long double> numbers;
};

ostream& operator<< (ostream& os, Matrix& mat); // to print a matrix in the console
Matrix operator* (const Column& c, const Row& r);

struct Impossible_operation{}; // for errors with impossible operations
struct Bad_value{}; // impossible values for intializations

#endif // MATRIX_H
