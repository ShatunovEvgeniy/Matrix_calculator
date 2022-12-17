#ifndef COLUMN_H
#define COLUMN_H

#include "matrix.h"

#include <vector>

class Vectors;

class Column : protected Matrix
{
public:
    Column(const int len); // empty column
    Column(const std::vector<long double>& num);
    Column(const std::vector<std::vector<long double>>& num);
    Column(const int len, const long double value); // column with same numbers

    Column(const Vectors& vec);

    Column operator+ (const Column& col) const; // sum of 2 columns
    Column& operator+= (const Column& col);      // sum of 2 columns

    Column operator- (const Column& col) const; // difference of 2 columns
    Column& operator-= (const Column& col);      // difference of 2 Columns

    Column operator* (const double num) const; // product of a column and a number
    Column& operator*= (const double num);      // product of a column and a number

    Column operator/ (const double num) const; // quotient of a column and a number
    Column& operator/= (const double num);      // quotient of a column and a number

    long double operator[] (const int index) const; // take a number of the column

    Row T() const;

    using Matrix :: zeros; // fill the column with zeros
    using Matrix :: ones; // fill the main diagonal with ones

    using Matrix :: get_num; // returns vector numbers
    using Matrix :: get_rows_count; // returns count of columns
    using Matrix :: get_columns_count; // returns count of rows

private:
    Column() = delete;
};

std::ostream& operator<< (std::ostream& os, Column& r); // to print a column in the console

#endif // COLUMN_H
