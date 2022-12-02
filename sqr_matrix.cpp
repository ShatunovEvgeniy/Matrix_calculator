#include "sqr_matrix.h"
#include "others_functions.h"

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
{}

Sqr_matrix::Sqr_matrix (const vector<vector<long double>>& num) :
    dimension{num.size()}, Matrix(num)
{}

Sqr_matrix::Sqr_matrix(const Matrix& m) :
    dimension{m.get_length()}, Matrix{m.get_num(), m.get_length(), m.get_width()}
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
            long double sub = m.numbers[k + i - 1] /  m.numbers[(i - 1) * dimension + i - 1];
            for (int j = i - 1; j < dimension; ++j)
                m.numbers[k + j] -= m.numbers[(i - 1) * dimension + j] * sub;
        }

    return m;
}

Sqr_matrix Sqr_matrix::diagonalization() const // returns matrix in diagonale forn
{
    Sqr_matrix m = *this;
    m = m.triangle();
    m = m.T();

    for (int i = 1; i < dimension; ++i)
        for (int k = i * dimension; k < dimension * dimension; k += dimension)
        {
            long double sub = m.numbers[k + i - 1] /  m.numbers[(i - 1) * dimension + i - 1];
            for (int j = i - 1; j < dimension; ++j)
                m.numbers[k + j] -= m.numbers[(i - 1) * dimension + j] * sub;
        }

    return m;
}

Sqr_matrix Sqr_matrix::inverse() const // returns inverse matrix
{}
Sqr_matrix Sqr_matrix::symmetric() const // returns symmetric matrix
{}
Sqr_matrix Sqr_matrix::skew_symmetric() const // returns skew symmetric matrix
{}

Sqr_matrix Sqr_matrix::T() const // returns transpose matrix
{
    Sqr_matrix m((*this).dimension, 0);
    for (int i = 0; i < m.dimension; ++i)
        for (int j = 0; j < m.dimension; ++j)
            m.numbers[i * m.dimension + j] = numbers[j * m.dimension + i];
    return m;
}

Sqr_matrix Sqr_matrix:: column_sort() const // returns matrix where max element of each columns places on position (i, i)
{
    Sqr_matrix m = *this;

    for (int i = 0; i < dimension; ++i)
    {
        long double max_num{INT_MIN};
        int max_index{-1};
        for (int j = i * dimension; j < dimension * dimension; j += dimension)
            if (m.numbers[i + j] > max_num)
            {
                max_num = m.numbers[i + j];
                max_index = j / dimension * dimension; // remember a string where max number with index (i, i) places
            }
        for (int j = 0; j < dimension; ++j)
            swap(m.numbers[i * dimension + j], m.numbers[max_index + j]); // changing places of string (max index) and i-string
    }

    return m;
}

void Sqr_matrix::zeros() // fill the sqr_matrix with zeros
{ for (auto number : numbers) number = 0; }

void Sqr_matrix::ones() // fill the sqr_matrix with ones
{ for (auto number : numbers) number = 1; }

long double Sqr_matrix::det() const // calculation of determination
{
    if (numbers.size() == 1)
        return numbers[0];

    Sqr_matrix mat = (*this).triangle(); // triangle matrix

    vector<long double> num; // new numbers vector
    for (int j = 0; j < dimension * dimension; ++j)
        if (!(j < dimension || (j % dimension == 0))) // if not (first row or first column)
            num.push_back(mat.numbers[j]);

    Sqr_matrix m{num}; // matrix with less size to call new det function

    return mat.numbers[0] * m.det();
}

vector<long double> Sqr_matrix::get_num() const
{ return numbers; }

int Sqr_matrix::get_width() const
{ return dimension; }

int Sqr_matrix::get_length() const
{ return dimension; }

/// Operators
Sqr_matrix Sqr_matrix::operator+ (const Sqr_matrix& mat) const // sum of 2 matrixes
{ return Sqr_matrix(Matrix(*this) + Matrix(mat)); }

void Sqr_matrix::operator+= (const Sqr_matrix& mat) // sum of 2 matrixes
{ *this = *this + mat; }

Sqr_matrix Sqr_matrix::operator- (const Sqr_matrix& mat) const // difference of 2 matrixes
{ return Sqr_matrix(Matrix(*this) - Matrix(mat)); }

void Sqr_matrix::operator-= (const Sqr_matrix& mat) // difference of 2 Smatrixes
{ *this = *this - mat; }

Sqr_matrix Sqr_matrix::operator* (const Sqr_matrix& mat) const // product of 2 matrixes
{ return Matrix(*this) * Matrix(mat); }

void Sqr_matrix::operator*= (const Sqr_matrix& mat) // product of 2 matrixes
{ *this = (*this) * mat; }

Sqr_matrix Sqr_matrix::operator* (const double& number) const // product of every numbers of a matrix and a number
{ return Matrix(*this) * number; }

void Sqr_matrix::operator*= (const double& number) // product of every numbers of a matrix and a number
{ *this = (*this) * number; }

Sqr_matrix Sqr_matrix::operator/ (const double& number) const // qoutient of every numbers of a matrix and a number
{ return Sqr_matrix(Matrix(*this) / number); }

void Sqr_matrix::operator/= (const double& number) // quotient of every numbers of a matrix and a number
{ *this = (*this) / number; }

Row Sqr_matrix::operator[] (const int index) const // take a row of the matrix
{ return Matrix(*this)[index]; }

ostream& operator<< (ostream& os, Sqr_matrix& mat) // to print a matrix in the console
{
    for (int i = 0; i < mat.get_width() * mat.get_length(); ++i)
    {
        os << mat.get_num()[i] << " ";
        if ((i + 1) % mat.get_width() == 0)
            os << endl;
    }
    os << endl;
    return os;
}
