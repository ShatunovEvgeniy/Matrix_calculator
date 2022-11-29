#include "column.h"

/// Constructors
Column::Column(const vector <long double>& num) :
    Matrix{num, (int)num.size(), 1}
{}

Column::Column(int n) : // empty column
    Matrix{1, n}
{}

/// Methods
vector<long double> Column::get_num() const
{
    return numbers;
}

int Column::get_width() const
{
    return width;
}

int Column:: get_length() const
{
    return length;
}

/// Operators
long double Column::operator[] (int i) const // take a number of the column
{
    return numbers[i];
}

Column Column::operator+ (const Column& col) const // sum of 2 columns
{
    Column result{length};

    if (col.length != length)
        throw runtime_error("Columns have different size");

    else if (numbers.empty() || col.get_num().empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] + col.numbers[i]);
    return result;
}

void Column::operator+= (const Column& Column) // sum of 2 columns
{
    *this = *this + Column;
}

Column Column::operator- (const Column& col) const // difference of 2 columns
{
    Column result{length};

    if (col.length != length)
        throw runtime_error("Columns have different size");

    else if (numbers.empty() || col.get_num().empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] - col.numbers[i]);
    return result;
}

void Column::operator-= (const Column& col) // difference of 2 columns
{
    *this = *this - col;
}

Column Column::operator* (double num) const // product of a column and a number
{
    Column result{length};
    if (numbers.empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] * num);
    return result;
}

void Column::operator*= (double num) // product of a column and a number
{
    *this = *this * num;
}

Column Column::operator/ (double num) const // quotient of a column and a number
{
    Column result{length};
    if (numbers.empty())
        throw runtime_error("Column is empty");

    else if (num == 0)
        throw runtime_error("Divided by zero");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]/num);
    return result;
}

void Column::operator/= (double num) // quotient of a column and a number
{
    *this = *this / num;
}

ostream& operator<< (ostream& os, Column& c) // to print a column in the console
{
    for (int i = 0; i < c.get_width(); ++i)
    {
        os << c.get_num()[i] << endl;
    }
    return os;
}
