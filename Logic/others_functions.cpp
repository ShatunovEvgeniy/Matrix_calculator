#include "others_functions.h"

using namespace std;

template <typename T>
vector<T> slicing(vector<T> const& v, int X, int Y) // slice of a vector
{

    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;

    // Copy the element
    vector<T> vec(first, last);

    // Return the results
    return vec;
}
