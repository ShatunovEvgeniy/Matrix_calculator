#ifndef COLUMN_H
#define COLUMN_H

#include "matrix.h"

#include <vector>

class Column : protected Matrix
{
public:
    Column(const int len); // empty column
    Column(const std::vector<long double>& num);
    Column(const std::vector<std::vector<long double>>& num);
    Column(const int len, const long double value); // column with same numbers

    Column operator+ (const Column& col) const; // sum of 2 columns
    void operator+= (const Column& col);             // sum of 2 columns

    Column operator- (const Column& col) const; // difference of 2 columns
    void operator-= (const Column& col);             // difference of 2 Columns

    Column operator* (const double num) const; // product of a column and a number
    void operator*= (const double num);             // product of a column and a number

    Column operator/ (const double num) const; // quotient of a column and a number
    void operator/= (const double num);             // quotient of a column and a number

    long double operator[] (const int index) const; // take a number of the column

    Row T() const;

    std::vector<long double> get_num() const override; // returns vector numbers
    int get_width() const override;  // returns width
    int get_length() const override; // returns length

    void zeros() override; // fill the column with zeros
    void ones() override;  // fill the column with ones

private:
    Column() = delete;
};

std::ostream& operator<< (std::ostream& os, Column& r); // to print a column in the console

#endif // COLUMN_H
