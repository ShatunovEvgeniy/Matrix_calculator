#include "row.h"

/// Constructors
Row::Row(vector <long double>& num) :
    Matrix{num, 1, (int)num.size()}
{}

Row::Row(int n) : // empty row
    Matrix{n, 1}
{}

/// Methods
vector<long double> Row::get_num() const
{
    return numbers;
}

int Row::get_width() const
{
    return width;
}

int Row:: get_length() const
{
    return length;
}

///Operators
long double Row::operator[] (int i) const // take a number of the row
{
    return numbers[i];
}

Row Row::operator+ (const Row& row) const // sum of 2 rows
{
    Row result{length};

    if (row.length != length)
    {
        throw Impossible_operation();
    }
    else if (numbers.empty())
    {
        throw Impossible_operation();
    }

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] + row.numbers[i]);
    return result;
}

void Row::operator+= (const Row& row1) // sum of 2 rows
{
    *this = *this + row1;
}

Row Row::operator- (const Row& row) const // difference of 2 rows
{
    Row result{length};

    if (row.length != length)
    {
        throw Impossible_operation();
    }
    else if (numbers.empty())
    {
        throw Impossible_operation();
    }

    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i] - row.numbers[i]);
    return result;
}

void Row::operator-= (const Row& row1) // difference of 2 rows
{
    *this = *this - row1;
}

Row Row::operator* (double num) const // product of a row and a number
{
    Row result{length};
    if (numbers.empty())
    {
        throw Impossible_operation();
    }
    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]*num);
    return result;
}

void Row::operator*= (double num) // product of a row and a number
{
    *this = *this * num;
}

Row Row::operator/ (double num) const // quotient of a row and a number
{
    Row result{length};
    if (numbers.empty())
    {
        throw Impossible_operation();
    }
    for (int i = 0; i < numbers.size(); ++i)
            result.numbers.push_back(numbers[i]/num);
    return result;
}

void Row::operator/= (double num) // quotient of a row and a number
{
    *this = *this / num;
}

ostream& operator<< (ostream& os, Row& r) // to print a row in the console
{
    for (int i = 0; i < r.get_width() * r.get_length(); ++i)
    {
        os << r.get_num()[i] << " ";
        if ((i + 1) % r.get_width() == 0)
            os << endl;
    }
    os << endl;
    return os;
}
