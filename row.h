#ifndef ROW_H
#define ROW_H

using namespace std;

#include <vector>

#include "matrix.h"

class Row : private Matrix
{
public:
    Row(vector<long double>& num);
};

template <typename T>
vector<T> slicing(vector<T> const& v, int X, int Y);

#endif // ROW_H
