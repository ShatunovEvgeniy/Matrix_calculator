#include "matrix.h"
#include "row.h"
#include "column.h"
#include "sqr_matrix.h"

#include <iomanip>

using namespace std;

/// Constructors
Matrix::Matrix(const int len, const int wid) : // empty matrix
    row_count{len}, column_count{wid}, numbers{vector<long double>(len * wid)}
{
    if (len <= 0 and wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");
}

Matrix::Matrix(const vector<vector<long double>>& num) :
    row_count{num.size()}, column_count{num[0].size()}
{
    for (auto x : num)
    {
        if (x.size() != column_count)
            throw runtime_error("Rows of a matrix are different");

        for (auto y : x)
            numbers.push_back(y);
    }
}

Matrix::Matrix(const int len, const int wid, const long double value) : // matrix with same numbers
    row_count{len}, column_count{wid}
{
    if (len <= 0 || wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");

    numbers = vector<long double>(len * wid, value);
}

Matrix::Matrix(const vector<long double>& num, const int len, const int wid) : // for columns and rows
    numbers{num}, row_count{len}, column_count{wid}
{
    if (len * wid != num.size())
        throw runtime_error("Vector has wrong size");
    if (len <= 0 and wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");
}

Matrix::Matrix(const Column &c) :
    row_count {c.get_rows_count()}, column_count {1}, numbers {c.get_num()}
{}

Matrix::Matrix(const Row &r) :
    row_count {1}, column_count {r.get_columns_count()}, numbers {r.get_num()}
{}

Matrix::Matrix(const Sqr_matrix& m) :
    row_count {m.get_rows_count()}, column_count {m.get_columns_count()}, numbers {m.get_num()}
{}

/// Methods
vector<long double> Matrix:: get_num() const // returns vector numbers
{ return numbers; }

int Matrix::get_columns_count() const // returns width
{ return column_count; }

int Matrix::get_rows_count() const // returns length
{ return row_count; }

void Matrix::zeros() // fill the matrix with zeros
{ this->numbers = vector<long double>(row_count * column_count, 0); }

void Matrix::ones() // fill the matrix with ones
{
    this->numbers = vector<long double>(row_count * column_count, 0);
    for (int i = 0; i < min(row_count, column_count); ++i)
        this->numbers[i + i * column_count] = 1;
}

Matrix Matrix::T() const
{
    Matrix m(this->column_count, this->row_count, 0);
    for (int i = 0; i < m.row_count; ++i)
        for (int j = 0; j < m.column_count; ++j)
            m.numbers[i * m.column_count + j] = numbers[j * m.row_count + i];
    return m;
}
/// Operators
Row Matrix::operator[] (const int index) const // take a row of the matrix
{
    if (index < 0)
        throw runtime_error("Index mustn't be less than zero");

    else if (numbers.empty())
            throw runtime_error("Matrix is empty");

    vector<long double> num(column_count);
    copy(numbers.begin() + column_count * index, numbers.begin() + column_count * (index + 1), num.begin());
    return Row{num};
}

Matrix Matrix::operator+ (const Matrix& mat) const // sum of 2 matrixes
{
    Matrix result = *this;
    return result += mat;
}

Matrix& Matrix::operator+= (const Matrix& mat) // sum of 2 matrixes
{
    if (mat.row_count != row_count || mat.column_count != column_count)
        throw runtime_error("You can't sum matrixes of different sizes");

    else if (numbers.empty() || mat.get_num().empty())
        throw runtime_error("The matrix are empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] += mat.numbers[i];
    return *this;
}

Matrix Matrix::operator- (const Matrix& mat) const //difference of 2 matrixes
{
    Matrix result = *this;
    return result -= mat;
}

Matrix& Matrix::operator-= (const Matrix& mat) // difference of 2 matrixes
{
    if (mat.row_count != row_count || mat.column_count != column_count)
        throw runtime_error("You can't sum matrixes of different sizes");

    else if (numbers.empty() || mat.get_num().empty())
        throw runtime_error("The matrix are empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] -= mat.numbers[i];
    return *this;
}

Matrix Matrix::operator* (const double number) const // product of every numbers of a matrix and a number
{
    Matrix result = *this;
    return result *= number;
}

Matrix& Matrix::operator*= (const double number) // product of every numbers of a matrix and a number
{
    if (numbers.empty())
        throw runtime_error("The matrix are empty");

    for (int i = 0; i < column_count * row_count; ++i)
        numbers[i] *= number;
    return *this;
}

Matrix Matrix::operator/(const double number) const // qoutient of every numbers of a matrix and a number
{
    Matrix result = *this;
    return result /= number;
}

Matrix& Matrix::operator/= (const double number) // qoutient of every numbers of a matrix and a number
{
    if (numbers.empty())
        throw runtime_error("The matrix are empty");

    for (int i = 0; i < column_count * row_count; ++i)
        numbers[i] /= number;
    return *this;
}

Matrix Matrix::operator* (const Matrix& mat) const // product of 2 matrixes
{
    Matrix result = *this;
    return result *= mat;
}

Matrix& Matrix::operator*= (const Matrix& mat) // product of 2 matrixes
{
    if (column_count != mat.row_count)
        throw runtime_error("Wrong size of matrixes");

    Matrix result{row_count, mat.column_count};
    result.numbers.clear();
    for (int i = 0; i < row_count; ++i)
        for (int j = 0; j < mat.column_count; ++j)
        {
            long double sum{0};
            for (int k = 0; k < column_count; ++k)
                // i * width - row[i] of first matrix
                // k * mat.width (0 < k < mat.length) - numbers of columns[j] of second matrix
                sum += numbers[i * column_count + k] * mat.numbers[k * mat.column_count + j];
            result.numbers.push_back(sum);
        }
    *this = result;
    return *this;
}

ostream& operator<< (ostream& os, Matrix& mat) // to print a matrix in the console
{
    os << fixed << setprecision(2) << left;
    for (int i = 0; i < mat.get_columns_count() * mat.get_rows_count(); ++i)
    {
        os << setw(8) << mat.get_num()[i] << setw(8);
        if ((i + 1) % mat.get_columns_count() == 0) // end of a row
            os << endl;
    }
    os << endl;
    return os;
}

Matrix operator* (const Column& c, const Row& r)
{ return Matrix(c) * Matrix(r); }

