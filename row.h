#ifndef ROW_H
#define ROW_H

#include "matrix.h"

#include <vector>

class Row : private Matrix
{
public:
    Row() = delete;
    Row(int n); // empty row
    Row(const std::vector<long double>& num);

    Row operator+ (const Row& row) const; // sum of 2 rows
    void operator+= (const Row& row); // sum of 2 rows

    Row operator- (const Row& row) const; // difference of 2 rows
    void operator-= (const Row& row); // difference of 2 rows

    Row operator* (double num) const; // product of a row and a number
    void operator*= (double num); // product of a row and a number

    Row operator/ (double num) const; // quotient of a row and a number
    void operator/= (double num); // quotient of a row and a number

    long double operator[] (int i) const; // take a number of the row

    std::vector<long double> get_num() const override;
    int get_width() const override;
    int get_length() const override;
};

std::ostream& operator<< (std::ostream& os, Row& r); // to print a row in the console

#endif // ROW_H
