#ifndef SQR_Sqr_matrix_H
#define SQR_Sqr_matrix_H

#include "matrix.h"
#include "row.h"
#include "others_functions.h"

class Sqr_matrix : private Matrix
{
public:
    Sqr_matrix(const int d); // n = dimension
    Sqr_matrix(const std::vector<long double>& num);
    Sqr_matrix(const std::vector<std::vector<long double>> &num);
    Sqr_matrix(const int d, const long double value); // matrix with same numbers

    Sqr_matrix operator+ (const Sqr_matrix& mat) const; // sum of 2 matrixes
    void operator+= (const Sqr_matrix& mat); // sum of 2 matrixes

    Sqr_matrix operator- (const Sqr_matrix& mat) const; // difference of 2 matrixes
    void operator-= (const Sqr_matrix& mat); // difference of 2 Smatrixes

    Sqr_matrix operator* (const Sqr_matrix& mat) const; // product of 2 matrixes
    void operator*= (const Sqr_matrix& mat); // product of 2 matrixes

    Sqr_matrix operator* (const double& number) const; // product of every numbers of a matrix and a number
    void operator*= (const double& number); // product of every numbers of a matrix and a number

    Sqr_matrix operator/ (const double& number) const; // qoutient of every numbers of a matrix and a number
    void operator/= (const double& number); // quotient of every numbers of a matrix and a number

    using Matrix::operator[]; // take a row of the matrix

    Sqr_matrix triangle() const; // returns matrix in triangle form
    Sqr_matrix diagonalization() const; // returns matrix in diagonale forn
    Sqr_matrix inverse() const; // returns inverse matrix
    Sqr_matrix symmetric() const; // returns symmetric matrix
    Sqr_matrix skew_symmetric() const; // returns skew symmetric matrix
    Sqr_matrix T() const; // returns transpose matrix
    Sqr_matrix column_sort() const; // returns matrix where max element of each rows places on position (i, i)

    void zeros() override; // fill the matrix with zeros
    void ones() override; // fill the matrix with ones

    long double det() const; // calculation of determination

    std::vector<long double> get_num() const override; // returns vector numbers
    int get_width() const override; // returns width
    int get_length() const override; // returns length

private:
    Sqr_matrix() = delete;
    Sqr_matrix(const Matrix& m);
    int dimension{0}; // dimension is size of a square matrix (dimension x dimension)
};

std::ostream& operator<< (std::ostream& os, Sqr_matrix& mat); // to print a matrix in the console

Sqr_matrix ones(int n);

#endif // SQR_Sqr_matrix_H
