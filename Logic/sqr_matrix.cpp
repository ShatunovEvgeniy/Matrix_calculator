#include "sqr_matrix.h"

#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

/// Constructors
Sqr_matrix::Sqr_matrix (const int d)  : // empty matrix
    dimension{d}, Matrix{d, d}
{}

Sqr_matrix::Sqr_matrix (const vector<long double>& num) :
    dimension{trunc(sqrt(num.size()))}, Matrix{num, trunc(sqrt(num.size())), trunc(sqrt(num.size()))}
{
    if (fmod(sqrt(num.size()), 1) != 0)
        throw runtime_error("It's impossible to make Sqr_matrix from this vector (wrong size of the vector)");
}

Sqr_matrix::Sqr_matrix (const vector<vector<long double>>& num) :
    dimension{num.size()}, Matrix(num)
{}

Sqr_matrix::Sqr_matrix(const Matrix& m) :
    dimension{m.get_rows_count()}, Matrix{m.get_num(), m.get_rows_count(), m.get_columns_count()}
{}

Sqr_matrix::Sqr_matrix(const int d, long double value) :
    dimension{d}, Matrix{d, d, value}
{}

/// Methods
Sqr_matrix Sqr_matrix::triangle() const // returns matrix in triangle form
{
    Sqr_matrix m = *this;

    m = m.column_sort();

    for (int i = 1; i < dimension; ++i)
        for (int k = i * dimension; k < dimension * dimension; k += dimension)
        {
            if (m.numbers[(i - 1) * dimension + i - 1] == 0)
            {
                m = m.column_sort();
                if (m.numbers[(i - 1) * dimension + i - 1] == 0)
                    return m;
            }
            long double sub = m.numbers[k + i - 1] /  m.numbers[(i - 1) * dimension + i - 1];
            for (int j = i - 1; j < dimension; ++j)
                m.numbers[k + j] -= m.numbers[(i - 1) * dimension + j] * sub;
        }

    return m;
}

Sqr_matrix Sqr_matrix:: column_sort() // returns matrix which has max element of each rows places on position (i, i)
{
    Sqr_matrix m = *this;

    for (int i = 0; i < dimension; ++i)
    {
        long double max_num{INT_MIN};
        int max_index{-1};
        for (int j = i * dimension; j < dimension * dimension; j += dimension)
            if (abs(m.numbers[i + j]) > max_num)
            {
                max_num = abs(m.numbers[i + j]);
                max_index = j / dimension * dimension; // remember a string where max number with index (i, i) places
            }

        if (max_index != i * dimension)
        {
            m.permutations++;
            for (int j = 0; j < dimension; ++j)
                swap(m.numbers[i * dimension + j], m.numbers[max_index + j]); // changing places of string (max index) and i-string
        }
    }
    return m;
}

long double Sqr_matrix::det() const // calculation of determination
{
    if (numbers.size() == 1)
        return numbers[0];

    Sqr_matrix mat = *this;
    mat = mat.triangle(); // triangle matrix

    vector<long double> num; // new numbers vector
    for (int j = 0; j < dimension * dimension; ++j)
        if (!(j < dimension || (j % dimension == 0))) // if not (first row or first column)
            num.push_back(mat.numbers[j]);

    Sqr_matrix m{num}; // matrix with less size to call new det function

    return pow(-1, mat.permutations) * mat.numbers[0] * m.det();
}

Sqr_matrix Sqr_matrix::diagonalization() const // returns matrix in diagonale forn
{
    Sqr_matrix m = *this;
    m = m.triangle();
    m = m.T();

    for (int i = 1; i < dimension; ++i)
        for (int k = i * dimension; k < dimension * dimension; k += dimension)
        {
            if (m.numbers[(i - 1) * dimension + i - 1] == 0)
            {
                m = m.column_sort();
                if (m.numbers[(i - 1) * dimension + i - 1] == 0)
                    return m;
            }
            long double sub = m.numbers[k + i - 1] /  m.numbers[(i - 1) * dimension + i - 1];
            for (int j = i - 1; j < dimension; ++j)
                m.numbers[k + j] -= m.numbers[(i - 1) * dimension + j] * sub;
        }

    return m;
}

Sqr_matrix Sqr_matrix::inverse() const // returns inverse matrix using adjugate matrix divided by detemination
{
    long double determinate = this->det();
    if (determinate == 0)
        throw runtime_error("Impossible to find inverse matrix: determinate = 0");

    Sqr_matrix m{dimension, 0};
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
        {
            Sqr_matrix elem_minor = this->minor(i, j); // finds the minor of (i, j) element
            m.numbers[i * dimension + j] = pow(-1, i + j) * elem_minor.det() / determinate;
        }
    return m.T();
}

Sqr_matrix Sqr_matrix::symmetric() const // returns symmetric matrix
{
    Sqr_matrix m = *this;
    for (int i = 1; i < dimension; ++i)
        for (int k = 0; k < i; ++k)
            m.numbers[i * dimension + k] = numbers[k * dimension + i];
    return m;
}

Sqr_matrix Sqr_matrix::skew_symmetric() const // returns skew symmetric matrix
{
    Sqr_matrix m = *this;
    for (int i = 0; i < dimension; ++i)
        for (int k = 0; k < dimension - i - 1; ++k)
            m.numbers[(dimension - k - 1) * dimension + dimension - i - 1] = numbers[i * dimension + k];
    return m;
}

Sqr_matrix Sqr_matrix::T() const // returns transpose matrix
{
    Sqr_matrix m((*this).dimension, 0);
    for (int i = 0; i < m.dimension; ++i)
        for (int j = 0; j < m.dimension; ++j)
            m.numbers[i * m.dimension + j] = numbers[j * m.dimension + i];
    return m;
}

Sqr_matrix Sqr_matrix:: minor(int i, int j) const // finds a minor of an element
{
    Sqr_matrix res{dimension - 1};
    res.numbers.clear();
    for (int row = 0; row < dimension; ++row)
        for (int column = 0; column < dimension; ++column)
            if(row != i & column != j)
                res.numbers.push_back((*this)[row][column]);
    return res;
}

Sqr_matrix Sqr_matrix::matrix_pow(const int degree) // raise a sqr_matrix to a power
{
    Sqr_matrix result = *this;
    for (int i = 1; i < degree; ++i)
        result *= *this;
    return result;
}

/// Operators
Sqr_matrix Sqr_matrix::operator+ (const Sqr_matrix& mat) const // sum of 2 matrixes
{ return Sqr_matrix(Matrix(*this) + Matrix(mat)); }

Sqr_matrix& Sqr_matrix::operator+= (const Sqr_matrix& mat) // sum of 2 matrixes
{ return *this = *this + mat; }

Sqr_matrix Sqr_matrix::operator- (const Sqr_matrix& mat) const // difference of 2 matrixes
{ return Sqr_matrix(Matrix(*this) - Matrix(mat)); }

Sqr_matrix& Sqr_matrix::operator-= (const Sqr_matrix& mat) // difference of 2 Smatrixes
{ return *this = *this - mat; }

Sqr_matrix Sqr_matrix::operator* (const Sqr_matrix& mat) const // product of 2 matrixes
{ return Matrix(*this) * Matrix(mat); }

Sqr_matrix& Sqr_matrix::operator*= (const Sqr_matrix& mat) // product of 2 matrixes
{ return *this = (*this) * mat; }

Sqr_matrix Sqr_matrix::operator* (const double number) const // product of every numbers of a matrix and a number
{ return Matrix(*this) * number; }

Sqr_matrix& Sqr_matrix::operator*= (const double number) // product of every numbers of a matrix and a number
{ return *this = (*this) * number; }

Sqr_matrix Sqr_matrix::operator/ (const double number) const // qoutient of every numbers of a matrix and a number
{ return Sqr_matrix(Matrix(*this) / number); }

Sqr_matrix& Sqr_matrix::operator/= (const double number) // quotient of every numbers of a matrix and a number
{ return *this = (*this) / number; }

ostream& operator<< (ostream& os, Sqr_matrix& mat) // to print a matrix in the console
{
    for (int i = 0; i < mat.get_columns_count() * mat.get_rows_count(); ++i)
    {
        os << mat.get_num()[i] << " ";
        if ((i + 1) % mat.get_columns_count() == 0)
            os << endl;
    }
    os << endl;
    return os;
}
