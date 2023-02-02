#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

class Column;
class Row;
class Sqr_matrix;
class Vectors;

class Matrix
{
public:
    Matrix(const int len, const int wid); // empty matrix
    Matrix(const std::vector<std::vector<long double>>& num);
    Matrix(const std::vector<long double>& num, const int len, const int wid);
    Matrix(const int len, const int wid, const long double value); // matrix with same numbers

    Matrix(const Column& c);
    Matrix(const Row& r);
    Matrix(const Sqr_matrix& m);
    Matrix(const Vectors& v);

    Matrix operator+ (const Matrix& mat) const ; // sum of 2 matrixes
    Matrix& operator+= (const Matrix& mat); // sum of 2 matrixes

    Matrix operator- (const Matrix& mat) const; // difference of 2 matrixes
    Matrix& operator-= (const Matrix& mat); // difference of 2 matrixes

    Matrix operator* (const Matrix& mat) const; // product of 2 matrixes
    Matrix& operator*= (const Matrix& mat); // product of 2 matrixes

    Matrix operator* (const double number) const; // product of every numbers of a matrix and a number
    Matrix& operator*= (const double number); // product of every numbers of a matrix and a number

    Matrix operator/ (const double number) const; // qoutient of every numbers of a matrix and a number
    Matrix& operator/= (const double number); // quotient of every numbers of a matrix and a number

    Row operator[] (const int index) const; // take a row of the matrix

    Matrix T() const;

    std::vector<long double> get_num() const; // returns vector numbers
    int get_columns_count() const; // returns count of columns
    int get_rows_count() const; // returns count of rows

    virtual void zeros(); // fill the matrix with zeros
    virtual void ones(); // fill the main diagonal with ones

protected:
    int row_count{0};
    int column_count{0};
    std::vector<long double> numbers;

private:
    Matrix() = delete;
};

std::ostream& operator<< (std::ostream& os, Matrix& mat); // to print a matrix in the console
Matrix operator* (const Column& c, const Row& r);

#endif // MATRIX_H
