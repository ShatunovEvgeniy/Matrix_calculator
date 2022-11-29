#include "vector.h"

#include <cmath>

/// Constructor
Vectors::Vectors(const vector<long double>& num) :
    Column{num}
{
    if (numbers.size() > 3)
        throw runtime_error("Interesting vector");
}

/// Methods
Vectors Vectors::vec_prod(const Vectors& vec) const // vector product
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad product");

    else if (numbers.size() != 3)
        throw runtime_error("Bad size");

    long double x = numbers[1] * vec.numbers[2] - numbers[2] * vec.numbers[1];
    long double y = numbers[2] * vec.numbers[0] - numbers[0] * vec.numbers[2];
    long double z = numbers[0] * vec.numbers[1] - numbers[1] * vec.numbers[0];

    vector<long double> ans {x, y, z};
    Vectors result{ans};
    return result;
}

long double Vectors::vec_length() const // length of the vector
{
    if (numbers.size() == 3)
        return sqrt(numbers[0] * numbers[0] + numbers[1] * numbers[1] + numbers[2] * numbers[2]);
    else if (numbers.size() == 2)
        return sqrt(numbers[0] * numbers[0] + numbers[1] * numbers[1]);
    else
        return numbers[0];
}

vector<long double> Vectors:: get_num() const
{
    return numbers;
}

int Vectors::get_width() const
{
    return width;
}

int Vectors::get_length() const
{
    return length;
}

/// Operators
Vectors Vectors::operator+ (const Vectors& vec) const // sum of 2 vectors
{
    Vectors result{numbers};
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");
    for (size_t i = 0; i < numbers.size(); i++)
        result.numbers[i] += vec.numbers[i];

    return result;
}

void Vectors::operator+= (const Vectors& vec) // sum of 2 vectors
{
    *this = *this + vec;
}

Vectors Vectors::operator- (const Vectors& vec) const // difference of 2 vectors
{
    Vectors result{numbers};

    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");

    for (size_t i = 0; i < numbers.size(); i++)
        result.numbers[i] -= vec.numbers[i];

    return result;
}

void Vectors::operator-= (const Vectors& vec) // difference of 2 vectors
{
    *this = *this - vec;
}

Vectors Vectors::operator* (const Vectors& vec) const // scalar product
{
    Vectors result{numbers};

    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");
    for (size_t i = 0; i < numbers.size(); i++)
        result.numbers[i] *= vec.numbers[i];

    return result;
}

void Vectors::operator*= (const Vectors& vec) // scalar product
{
    *this = *this * vec;
}

Vectors Vectors::operator* (double num) const // product a vector and a number
{
    Vectors result{numbers};

    for (size_t i = 0; i < numbers.size(); i++)
        result.numbers[i] *= num;

    return result;
}

void Vectors::operator*= (double num) // product a vector and a number
{
    *this = *this * num;
}

Vectors Vectors::operator/ (double num) const  // quotient a vector and a number
{
    Vectors result{numbers};
    for (size_t i = 0; i < numbers.size(); i++)
        result.numbers[i] /= num;

    return result;
}

void Vectors::operator/= (double num)  // quotient a vector and a number
{
    *this = *this / num;
}

ostream& operator<< (ostream& os, Vectors& vec) // to print a column in the console
{
    for (int i = 0; i < vec.get_width(); ++i)
    {
        os << vec.get_num()[i] << endl;
    }
    return os;
}
