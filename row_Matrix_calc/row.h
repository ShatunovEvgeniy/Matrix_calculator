#ifndef ROW_H
#define ROW_H

using namespace std;

#include <vector>

#include "matrix.h"

class Row : private Matrix
{
public:
    Row(vector<long double>& num);
    Row(int n);
    void operator+= (const Row& row1);
    void operator-= (const Row& row1);
    void operator*= (double num);
    void operator/= (double num);
    Row operator+ (const Row& row1);
    Row operator- (const Row& row1);
    Row operator* (double num);
    Row operator/ (double num);
    long double operator[] (int i);
    void get_row();
    int get_width() const;
    int get_length() const;
    int get_num() const;
};
template <typename T>
vector<T> slicing(vector<T> const& v, int X, int Y);

#endif // ROW_H
