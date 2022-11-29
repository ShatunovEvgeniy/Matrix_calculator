#ifndef SQR_Sqr_matrix_H
#define SQR_Sqr_matrix_H

#include "matrix.h"
#include "row.h"

class Sqr_matrix : private Matrix
{
public:
    Sqr_matrix() = delete;
    Sqr_matrix(int n); // n = dimension
    Sqr_matrix(const vector<long double>& num);
    Sqr_matrix(const vector<vector<long double>> &num);
    Sqr_matrix(int n, long double x); // matrix with same numbers

    Sqr_matrix operator+ (const Sqr_matrix& mat); // sum of 2 matrixes
    void operator+= (const Sqr_matrix& mat); // sum of 2 matrixes

    Sqr_matrix operator- (const Sqr_matrix& mat); // difference of 2 matrixes
    void operator-= (const Sqr_matrix& mat); // difference of 2 Smatrixes

    Sqr_matrix operator* (const Sqr_matrix& mat); // product of 2 matrixes
    void operator*= (const Sqr_matrix& mat); // product of 2 matrixes

    Sqr_matrix operator* (const double& number); // product of every numbers of a matrix and a number
    void operator*= (const double& number); // product of every numbers of a matrix and a number

    Sqr_matrix operator/ (const double& number); // qoutient of every numbers of a matrix and a number
    void operator/= (const double& number); // quotient of every numbers of a matrix and a number

    Row operator[] (const int index); // take a row of the matrix

    Sqr_matrix triangle(); // returns matrix in triangle form
    Sqr_matrix diagonalization(); // returns matrix in diagonale forn
    Sqr_matrix inverse(); // returns inverse matrix
    Sqr_matrix symmetric(); // returns symmetric matrix
    Sqr_matrix skew_symmetric(); // returns skew symmetric matrix
    Sqr_matrix T(); // returns transpose matrix
    void zeros() override;

    long double det(); // calculation of determination

    vector<long double> get_num() const override;
    int get_width() const override;
    int get_length() const override;

private:

    Sqr_matrix(const Matrix& m);
    int dimension{0}; // dimension is size of a square matrix (dimension x dimension)
};

ostream& operator<< (ostream& os, Sqr_matrix& mat); // to print a matrix in the console

Sqr_matrix ones(int n);

#endif // SQR_Sqr_matrix_H
