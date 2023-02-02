#include "row.h"
#include "column.h"

using namespace std;

/// Constructors
Row::Row(const int len) : // empty row
    Matrix{len, 1}
{}

Row::Row(const vector<long double>& num) :
    Matrix{num, 1, (int)num.size()}
{}

Row::Row(const vector<vector<long double>>& num) :
    Matrix{num}
{}

Row::Row(const int len, const long double value) : // row with same numbers
    Matrix(1, len, value)
{}

/// Methods
Column Row::T() const
{
    return Column(this->numbers);
}

/// Operators
long double Row::operator[] (const int index) const // take a number of the row
{
    if (index < 0)
        throw runtime_error("Index mustn't be less than zero");

    else if (numbers.empty())
            throw runtime_error("Row is empty");

    return numbers[index];
}

Row Row::operator+ (const Row& row) const // sum of 2 rows
{
    Row result = *this;
    return result += row;
}

Row& Row::operator+= (const Row& row) // sum of 2 rows
{
    if (row.row_count != row_count)
        throw runtime_error("Rows have different size");

    else if (numbers.empty() || row.get_num().empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            numbers[i] += row.numbers[i];

    return *this;
}

Row Row::operator- (const Row& row) const // difference of 2 rows
{
    Row result = *this;
    return result -= row;
}

Row& Row::operator-= (const Row& row) // difference of 2 rows
{
    if (row.row_count != row_count)
        throw runtime_error("Rows have different size");

    else if (numbers.empty() || row.get_num().empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            numbers[i] -= row.numbers[i];

    return *this;
}

Row Row::operator* (const double num) const // product of a row and a number
{
    Row result = *this;
    return result;
}

Row& Row::operator*= (const double num) // product of a row and a number
{
    if (numbers.empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            numbers[i] *= num;

    return *this;
}

Row Row::operator/ (const double num) const // quotient of a row and a number
{
    Row result = *this;
    return result;
}

Row& Row::operator/= (const double num) // quotient of a row and a number
{
    if (numbers.empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            numbers[i] *= num;

    return *this;
}

ostream& operator<< (ostream& os, Row& r) // to print a row in the console
{
    for (auto i : r.get_num())
    {
        os << i << " ";
    }
    os << endl;
    return os;
}
