#include "column.h"
#include "row.h"
#include "vector.h"

using namespace std;

/// Constructors
Column::Column(const int len) : // empty column
    Matrix{1, len}
{}

Column::Column(const vector <long double>& num) :
    Matrix{num, num.size(), 1}
{}

Column::Column(const std::vector<std::vector<long double>>& num) :
    Matrix(num)
{}

Column::Column(const int len, const long double value) : // column with same numbers
    Matrix(len, 1, value)
{}

Column::Column(const Vectors& vec) :
    Matrix(vec.get_num(), vec.get_rows_count(), 1)
{}

/// Methods
Row Column::T() const
{
    return Row(this->numbers);
}

/// Operators
long double Column::operator[] (const int index) const // take a number of the column
{
    if (index < 0)
        throw runtime_error("Index mustn't be less than zero");

    else if (numbers.empty())
            throw runtime_error("Column is empty");

    return numbers[index];
}

Column Column::operator+ (const Column& col) const // sum of 2 columns
{
    Column result = *this;
    return result += col;
}

Column& Column::operator+= (const Column& col) // sum of 2 columns
{
    if (col.row_count != row_count)
        throw runtime_error("Columns have different size");

    else if (numbers.empty() || col.get_num().empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] += col.numbers[i];
    return *this;
}

Column Column::operator- (const Column& col) const // difference of 2 columns
{
    Column result = *this;
    return result -= col;
}

Column& Column::operator-= (const Column& col) // difference of 2 columns
{
    if (col.row_count != row_count)
        throw runtime_error("Columns have different size");

    else if (numbers.empty() || col.get_num().empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] -= col.numbers[i];
    return *this;
}

Column Column::operator* (const double num) const // product of a column and a number
{
    Column result = *this;
    return result *= num;
}

Column& Column::operator*= (const double num) // product of a column and a number
{
    if (numbers.empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] *= num;
    return *this;
}

Column Column::operator/ (const double num) const // quotient of a column and a number
{
    Column result = *this;
    return result /= num;
}

Column& Column::operator/= (const double num) // quotient of a column and a number
{
    if (numbers.empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
        numbers[i] /= num;
    return *this;
}

ostream& operator<< (ostream& os, Column& c) // to print a column in the console
{
    for (auto i : c.get_num())
    {
        os << i << endl;
    }
    return os;
}
