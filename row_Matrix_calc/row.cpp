#include "row.h"

Row::Row(vector <long double>& num) :
    Matrix{num, 1, (int)num.size()}
{}

Row::Row(int n)
    :Matrix{n, 1}
{}

void Row::operator+=(const Row& row1)
{
    if (row1.numbers.size() != numbers.size()) {
        throw Bad_value();
    }
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] += row1.numbers[i];
    }
    return;
}

void Row::operator-=(const Row& row1)
{
    if (row1.numbers.size() != numbers.size()) {
        throw Bad_value();
    }
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] -= row1.numbers[i];
    }
    return;
}

void Row::operator*=(double num)
{
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] *= num;
    }
    return;
}

void Row::operator/=(double num)
{
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] /= num;
    }
    return;
}

long double Row::operator[] (int i)
{
    return numbers[i];
}

template <typename T>
vector<T> slicing(vector<T> const& v, int X, int Y)
{

    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;

    // Copy the element
    vector<T> vector(first, last);

    // Return the results
    return vector;
}

void Row::get_row()
{
    for (long double i : numbers)
        cout<<i<<" ";
}

Row Row::operator+ (const Row& row) // sum of 2 rows
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

Row Row::operator- (const Row& row) // difference of 2 rows
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

Row Row::operator* (double num) // product of 2 rows
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

Row Row::operator/ (double num) // division of 2 rows
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
