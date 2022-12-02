#include "row.h"

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
{
    if (num.size() != 1)
        throw runtime_error("Wrong vector for initialization of the row");
}

Row::Row(const int len, const long double value) : // row with same numbers
    Matrix(1, len, value)
{}

/// Methods
vector<long double> Row::get_num() const // returns vector numbers
{ return numbers; }

int Row::get_width() const // returns width
{ return width; }

int Row:: get_length() const // returns length
{ return length; }

void Row::zeros() // fill the row with zeros
{ for (auto number : numbers) number = 0; }

void Row::ones() // fill the row with ones
{ for (auto number : numbers) number = 1; }

/// Operators
long double Row::operator[] (const int i) const // take a number of the row
{ return numbers[i]; }

Row Row::operator+ (const Row& row) const // sum of 2 rows
{
    Row result{length};

    if (row.length != length)
        throw runtime_error("Rows have different size");

    else if (numbers.empty() || row.get_num().empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] + row.numbers[i]);
    return result;
}

void Row::operator+= (const Row& row) // sum of 2 rows
{ *this = *this + row; }

Row Row::operator- (const Row& row) const // difference of 2 rows
{
    Row result{length};

    if (row.length != length)
        throw runtime_error("Rows have different size");

    else if (numbers.empty() || row.get_num().empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] - row.numbers[i]);
    return result;
}

void Row::operator-= (const Row& row) // difference of 2 rows
{ *this = *this - row; }

Row Row::operator* (const double num) const // product of a row and a number
{
    Row result{length};
    if (numbers.empty())
        throw runtime_error("Row is empty");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] * num);
    return result;
}

void Row::operator*= (const double num) // product of a row and a number
{ *this = *this * num; }

Row Row::operator/ (const double num) const // quotient of a row and a number
{
    Row result{length};
    if (numbers.empty())
        throw runtime_error("Row is empty");

    else if (num == 0)
        throw runtime_error("Divided by zero");

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]/num);
    return result;
}

void Row::operator/= (const double num) // quotient of a row and a number
{ *this = *this / num; }

ostream& operator<< (ostream& os, Row& r) // to print a row in the console
{
    for (int i = 0; i < r.get_length(); ++i)
    {
        os << r.get_num()[i] << " ";
    }
    os << endl;
    return os;
}
