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
    Row& operator+= (const Row& row); // sum of 2 rows

    Row operator- (const Row& row) const; // difference of 2 rows
    Row& operator-= (const Row& row); // difference of 2 rows

    Row operator* (const double num) const; // product of a row and a number
    Row& operator*= (const double num); // product of a row and a number

    Row operator/ (const double num) const; // quotient of a row and a number
    Row& operator/= (const double num); // quotient of a row and a number

    Column T() const;

    long double operator[] (const int i) const; // take a number of the row

    using Matrix :: zeros; // fill the column with zeros
    using Matrix :: ones;  // fill the main diagonal with ones

    using Matrix :: get_num; // returns vector numbers
    using Matrix :: get_rows_count; // returns count of columns
    using Matrix :: get_columns_count; // returns count of rows


private:
    Row() = delete;
};

std::ostream& operator<< (std::ostream& os, Row& r); // to print a row in the console

#endif // ROW_H
