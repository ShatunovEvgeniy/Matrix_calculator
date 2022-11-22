#include "row.h"

Row::Row(vector <long double>& num) :
    Matrix{num, 1, num.size()}
{}

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
