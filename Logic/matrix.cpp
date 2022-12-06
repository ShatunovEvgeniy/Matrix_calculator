#include "matrix.h"
#include "row.h"
#include "column.h"
#include "sqr_matrix.h"

using namespace std;
///
///Концепты!!!!!!!!!!!
///
/// Constructors
Matrix::Matrix(const int len, const int wid) : // empty matrix
    length{len}, width{wid}
{
    if (len <= 0 and wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");
}

Matrix::Matrix(const vector<vector<long double>>& num) :
    length{num.size()}, width{num[0].size()}
{
    for (auto x : num)
    {
        if (x.size() != width)
            throw runtime_error("Rows of a matrix are different");

        for (auto y : x)
            numbers.push_back(y);
    }
}

Matrix::Matrix(const int len, const int wid, const long double value) : // matrix with same numbers
    length{len}, width{wid}
{
    if (len <= 0 || wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");

    numbers = vector<long double>(len * wid, value);
}

Matrix::Matrix(const vector<long double>& num, const int len, const int wid) : // for columns and rows
    numbers{num}, length{len}, width{wid}
{
    if (len <= 0 and wid <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");
}

Matrix::Matrix(const Column &c) :
    length {c.get_length()}, width {1}, numbers {c.get_num()}
{}

Matrix::Matrix(const Row &r) :
    length {1}, width {r.get_width()}, numbers {r.get_num()}
{}

Matrix::Matrix(const Sqr_matrix& m) :
    length {m.get_length()}, width {m.get_width()}, numbers {m.get_num()}
{}

/// Methods
vector<long double> Matrix:: get_num() const // returns vector numbers
{ return numbers; }

int Matrix::get_width() const // returns width
{ return width; }

int Matrix::get_length() const // returns length
{ return length; }

void Matrix::zeros() // fill the matrix with zeros
{ numbers = vector<long double>(length, 0); }

void Matrix::ones() // fill the matrix with ones
{ numbers = vector<long double>(length, 1); }

Matrix Matrix::T() const
{
    Matrix m(this->width, this->length, 0);
    for (int i = 0; i < m.length; ++i)
        for (int j = 0; j < m.width; ++j)
            m.numbers[i * m.width + j] = numbers[j * m.length + i];
    return m;
}
/// Operators
Row Matrix::operator[] (const int index) const // take a row of the matrix
{
    if (index < 0)
        throw runtime_error("Index mustn't be less than zero");

    else if (numbers.empty())
            throw runtime_error("Matrix is empty");

    vector<long double> num(width);
    copy(numbers.begin() + width * index, numbers.begin() + width * (index + 1), num.begin());
    return Row{num};
}

Matrix Matrix::operator+ (const Matrix& mat) const // sum of 2 matrixes
{
    Matrix result{length, width};

    if (mat.length != length || mat.width != width)
    {
        throw runtime_error("You can't sum matrixes of different sizes");
    }
    else if (numbers.empty() || mat.get_num().empty())
    {
        throw runtime_error("The matrix are empty");
    }

    for (int i = 0; i < numbers.size(); ++i)
        result.numbers.push_back(numbers[i] + mat.numbers[i]);
    return result;
}

void Matrix::operator+= (const Matrix& mat) // sum of 2 matrixes
{ *this = *this + mat; }

Matrix Matrix::operator- (const Matrix& mat) const // difference of 2 matrixes
{
    Matrix result{length, width};

    if (mat.length != length || mat.width != width)
    {
        throw runtime_error("You can't subtract matrixes of different sizes");
    }
    else if (numbers.empty() || mat.get_num().empty())
    {
        throw runtime_error("The matrix are empty");
    }

    for (int i = 0; i < numbers.size(); ++i)
        result.numbers.push_back(numbers[i] - mat.numbers[i]);
    return result;
}

void Matrix::operator-= (const Matrix& mat) // difference of 2 matrixes
{ *this = *this - mat; }

Matrix Matrix::operator* (const double& number) const // product of every numbers of a matrix and a number
{
    Matrix result{length, width};

    if (numbers.empty())
    {
        throw runtime_error("The matrix are empty");
    }

    for (int i = 0; i < numbers.size(); ++i)
        result.numbers.push_back(numbers[i] * number);
    return result;
}

void Matrix::operator*= (const double& number) // product of every numbers of a matrix and a number
{ *this = *this * number; }

Matrix Matrix::operator/ (const double& number) const // product of every numbers of a matrix and a number
{
    Matrix result{length, width};

    if (numbers.empty())
    {
        throw runtime_error("The matrix are empty");
    }

    for (int i = 0; i < numbers.size(); ++i)
        result.numbers.push_back(numbers[i] / number);
    return result;
}

void Matrix::operator/= (const double& number) // product of every numbers of a matrix and a number
{ *this = *this / number; }

Matrix Matrix::operator* (const Matrix& mat) const // product of 2 matrixes
{
    if (width != mat.length)
        throw runtime_error("Wrong size of matrixes");

    Matrix result{length, mat.width};
    for (int i = 0; i < length; ++i)
        for (int j = 0; j < mat.width; ++j)
        {
            long double sum{0};
            for (int k = 0; k < width; ++k)
                // i * width - row[i] of first matrix
                // k * mat.width (0 < k < mat.length) - numbers of columns[j] of second matrix
                sum += numbers[i * width + k] * mat.numbers[k * mat.width + j];
            result.numbers.push_back(sum);
        }
    return result;
}

void Matrix::operator*= (const Matrix& mat) // product of 2 matrixes
{ *this = (*this) * mat; }

ostream& operator<< (ostream& os, Matrix& mat) // to print a matrix in the console
{
    for (int i = 0; i < mat.get_width() * mat.get_length(); ++i)
    {
        os << mat.get_num()[i] << " ";
        if ((i + 1) % mat.get_width() == 0) // end of a row
            os << endl;
    }
    os << endl;
    return os;
}


Matrix operator* (const Column& c, const Row& r)
{ return Matrix(c) * Matrix(r); }

