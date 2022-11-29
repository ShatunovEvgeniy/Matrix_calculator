#include "matrix.h"
#include "row.h"
#include "column.h"
#include "sqr_matrix.h"

/// Constructors
Matrix::Matrix(const int n, const int m) : // empty matrix
    length{n}, width{m}
{
    if (n <= 0 and m <= 0)
        throw runtime_error("Dimensions of a matrix have to be more than zero");
}

Matrix::Matrix(const vector<vector<long double>>& num) :
    length{num.size()}, width{num[0].size()}
{
    for (auto x : num)
    {
        if (x.size() != width)
            throw runtime_error("Strings of a matrix are different");
        for (auto y : x)
            numbers.push_back(y);
    }
}

Matrix::Matrix(const int n, const int m, const long double value) : // matrix with same numbers
    length{n}, width{m}
{
    for (int i = 0; i < n*m; ++i)
        numbers.push_back(value);
}

Matrix::Matrix(const vector<long double>& num, const int n, const int m) : // for columns and rows
    numbers{num}, length{n}, width{m}
{
    if (n <= 0 and m <= 0)
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
vector<long double> Matrix:: get_num() const
{
    return numbers;
}
int Matrix::get_width() const
{
    return width;
}
int Matrix::get_length() const
{
    return length;
}
void Matrix::zeros()
{
    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] = 0;
}

/// Operators
Row Matrix::operator[] (const int i) const // take a row of the matrix
{
    vector<long double> num(width);
    copy(numbers.begin() + width*i, numbers.begin() + width*(i+1), num.begin());
    return Row{num};
}

Matrix Matrix::operator+ (const Matrix& mat) const // sum of 2 matrixes
{
    Matrix result{length, width};

    if (mat.length != length || mat.width != width)
    {
        throw runtime_error("You can't add matrixes of different sizes");
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
{
    *this = *this + mat;
}

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
{
    *this = *this - mat;
}

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
{
    *this = *this * number;
}

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
{
    *this = *this / number;
}

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
                sum += numbers[i * width + k] * mat.numbers[k * mat.width + j]; // i * width - row[i] of first matrix
                                                                                                          // k * mat.width (0 < k < mat.length) - numbers of columns[j] of second matrix
            result.numbers.push_back(sum);
        }
   return result;
}

void Matrix::operator*= (const Matrix& mat) // product of 2 matrixes
{
    *this = (*this) * mat;
}

ostream& operator<< (ostream& os, Matrix& mat) // to print a matrix in the console
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


Matrix operator* (const Column& c, const Row& r)
{
    return Matrix(c) * Matrix(r);
}

