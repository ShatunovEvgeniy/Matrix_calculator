#include "column.h"
#include "row.h"

using namespace std;

/// Constructors
Column::Column(const int len) : // empty column
    Matrix{1, len}
{}

Column::Column(const vector <long double>& num) :
    Matrix{num, (int)num.size(), 1}
{}

Column::Column(const std::vector<std::vector<long double>>& num) :
    Matrix(num)
{}

Column::Column(const int len, const long double value) : // column with same numbers
    Matrix(len, 1, value)
{}

/// Methods
vector<long double> Column::get_num() const // returns vector numbers
{ return numbers; }

int Column::get_width() const // returns width
{ return width; }

int Column:: get_length() const  // returns length
{ return length; }

void Column::zeros() // fill the column with zeros
{ numbers = vector<long double>(length, 0); }

void Column::ones() // fill the column with ones
{ numbers = vector<long double>(length, 1); }

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
{ *this = *this + Column; }

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
{ *this = *this - col; }

Column Column::operator* (const double num) const // product of a column and a number
{
    Column result{length};
    if (numbers.empty())
        throw runtime_error("Column is empty");

    for (int i = 0; i < numbers.size(); ++i)
        result.numbers.push_back(numbers[i] * num);
    return result;
}

void Column::operator*= (const double num) // product of a column and a number
{ *this = *this * num; }

Column Column::operator/ (const double num) const // quotient of a column and a number
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

void Column::operator/= (const double num) // quotient of a column and a number
{ *this = *this / num; }

ostream& operator<< (ostream& os, Column& c) // to print a column in the console
{
    for (auto i : c.get_num())
    {
        os << i << endl;
    }
    return os;
}
