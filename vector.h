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
    void operator+= (const Vectors& vec); // sum of 2 vectors

    Vectors operator- (const Vectors& vec) const; // difference of 2 vectors
    void operator-= (const Vectors& vec); // difference of 2 vectors

    Vectors operator* (const Vectors& vec) const; // scalar product
    void operator*= (const Vectors& vec); // scalar product

    Vectors operator* (const double num) const; // product a vector and a number
    void operator*= (const double num); // product a vector and a number

    Vectors operator/ (const double num) const; // quotient a vector and a number
    void operator/= (const double num); // quotient a vector and a number

    using Column::operator[];

    Vectors vec_prod(const Vectors& vec) const; // vector product

    long double vec_length() const; // length of the vector

    std::vector<long double> get_num() const override; // returns vector numbers
    int get_width() const override; // returns width
    int get_length() const override; // returns length

    void zeros() override; // fill the vector with zeros
    void ones() override; // fill the vector with ones

private:
    Vectors() = delete;
};

std::ostream& operator<< (std::ostream& os, Vectors& vec); // to print a vector in the console

#endif // Vector_H
