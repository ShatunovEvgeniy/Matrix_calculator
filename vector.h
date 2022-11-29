#ifndef Vector_H
#define Vector_H

#include "column.h"

#include <vector>

class Vectors: private Column
{
public:
    Vectors (const vector<long double>& num);

    Vectors operator+ (const Vectors& vec) const; // sum of 2 vectors
    void operator+= (const Vectors& vec); // sum of 2 vectors

    Vectors operator- (const Vectors& vec) const; // difference of 2 vectors
    void operator-= (const Vectors& vec); // difference of 2 vectors

    Vectors operator* (const Vectors& vec) const; // scalar product
    void operator*= (const Vectors& vec); // scalar product

    Vectors operator* (double num) const; // product a vector and a number
    void operator*= (double num); // product a vector and a number

    Vectors operator/ (double num) const; // quotient a vector and a number
    void operator/= (double num); // quotient a vector and a number

    using Column::operator[];

    Vectors vec_prod(const Vectors& vec) const; // vector product

    long double vec_length() const; // length of the vector

    vector<long double> get_num() const override;
    int get_width() const override;
    int get_length() const override;
};

ostream& operator<< (ostream& os, Vectors& vec); // to print a vector in the console

#endif // Vector_H
