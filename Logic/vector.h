#ifndef Vector_H
#define Vector_H

#include "column.h"

#include <vector>

class Vectors: private Column
{
public:
    Vectors(const int count); // empty vector
    Vectors(const std::vector<long double> &num);

    Vectors(const Column& c);

    Vectors operator+ (const Vectors& vec) const; // sum of 2 vectors
    Vectors& operator+= (const Vectors& vec); // sum of 2 vectors

    Vectors operator- (const Vectors& vec) const; // difference of 2 vectors
    Vectors& operator-= (const Vectors& vec); // difference of 2 vectors

    Vectors operator* (const Vectors& vec) const; // scalar product
    Vectors& operator*= (const Vectors& vec); // scalar product

    Vectors operator* (const double num) const; // product a vector and a number
    Vectors& operator*= (const double num); // product a vector and a number

    Vectors operator/ (const double num) const; // quotient a vector and a number
    Vectors& operator/= (const double num); // quotient a vector and a number

    using Column::operator[];

    Vectors vec_prod(const Vectors& vec) const; // vector product

    long double vec_length() const; // length of the vector

    using Matrix :: zeros; // fill the column with zeros
    using Matrix :: ones;  // fill the main diagonal with ones

    using Matrix :: get_num; // returns vector numbers
    using Matrix :: get_rows_count; // returns count of columns
    using Matrix :: get_columns_count; // returns count of rows


private:
    Vectors() = delete;
};

std::ostream& operator<< (std::ostream& os, Vectors& vec); // to print a vector in the console

#endif // Vector_H
