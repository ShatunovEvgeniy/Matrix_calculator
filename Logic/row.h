#ifndef ROW_H
#define ROW_H

#include "matrix.h"

#include <vector>

class Row : private Matrix
{
public:
    Row(const int len); // empty row
    Row(const std::vector<long double>& num);
    Row(const std::vector<std::vector<long double>>& num);
    Row(const int len, const long double value); // row with same numbers

    Row operator+ (const Row& row) const; // sum of 2 rows
    void operator+= (const Row& row); // sum of 2 rows

    Row operator- (const Row& row) const; // difference of 2 rows
    void operator-= (const Row& row); // difference of 2 rows

    Row operator* (const double num) const; // product of a row and a number
    void operator*= (const double num); // product of a row and a number

    Row operator/ (const double num) const; // quotient of a row and a number
    void operator/= (const double num); // quotient of a row and a number

    Column T() const;

    long double operator[] (const int i) const; // take a number of the row

    std::vector<long double> get_num() const override; // returns vector numbers
    int get_width() const override; // returns width
    int get_length() const override; // returns length

    void zeros() override; // fill the row with zeros
    void ones() override; // fill the row with ones

private:
    Row() = delete;
};

std::ostream& operator<< (std::ostream& os, Row& r); // to print a row in the console

#endif // ROW_H
