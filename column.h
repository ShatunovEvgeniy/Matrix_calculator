#ifndef COLUMN_H
#define COLUMN_H

#include "matrix.h"

#include <vector>

using namespace std;

class Column : protected Matrix
{
public:
    Column() = delete;
    Column(int n); // empty column
    Column(const vector<long double>& num);

    Column operator+ (const Column& col) const; // sum of 2 columns
    void operator+= (const Column& col);             // sum of 2 columns

    Column operator- (const Column& col) const; // difference of 2 columns
    void operator-= (const Column& col);             // difference of 2 Columns

    Column operator* (double num) const; // product of a column and a number
    void operator*= (double num);             // product of a column and a number

    Column operator/ (double num) const; // quotient of a column and a number
    void operator/= (double num);             // quotient of a column and a number

    long double operator[] (int i) const; // take a number of the column

    vector<long double> get_num() const override;
    int get_width() const override;
    int get_length() const override;
};

ostream& operator<< (ostream& os, Column& r); // to print a Column in the console

#endif // COLUMN_H
