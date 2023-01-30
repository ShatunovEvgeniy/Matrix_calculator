#include "vector.h"

#include <cmath>

using namespace std;

/// Constructor
Vectors::Vectors(const int count) : // empty vector
    Column(count)
{
    if (count > 3)
        throw runtime_error("Vector's size have to be less than zero");
}

Vectors::Vectors(const vector<long double>& num) :
    Column{num}
{
    if (numbers.size() > 3)
        throw runtime_error("Interesting vector");
}

Vectors::Vectors(const Column& c) :
    Column(c.get_num())
{}

/// Methods
Vectors Vectors::vec_prod(const Vectors& vec) const // vector product
{
    if (!(numbers.size() == vec.numbers.size()) && numbers.size() == 3 && vec.numbers.size() == 3)
    {
        cout << numbers.size() << endl << vec.numbers.size() << endl;
        throw runtime_error("Vectors have to have 3 coordinates");
    }
    long double x = numbers[1] * vec.numbers[2] - numbers[2] * vec.numbers[1];
    long double y = numbers[2] * vec.numbers[0] - numbers[0] * vec.numbers[2];
    long double z = numbers[0] * vec.numbers[1] - numbers[1] * vec.numbers[0];

    vector<long double> ans {x, y, z};
    Vectors result{ans};
    return result;
}

long double Vectors::vec_length() const // length of the vector
{
    long double result{0};
    for (auto i : numbers)
        result += i * i;
    return sqrt(result);
}

/// Operators
Vectors Vectors::operator+ (const Vectors& vec) const // sum of 2 vectors
{
    Vectors result = *this;
    return result += vec;
}

Vectors& Vectors::operator+= (const Vectors& vec) // sum of 2 vectors
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Vectors have different size");

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] += vec.numbers[i];
    return *this;
}

Vectors Vectors::operator- (const Vectors& vec) const // difference of 2 vectors
{
    Vectors result = *this;
    return result -= vec;
}

Vectors& Vectors::operator-= (const Vectors& vec) // difference of 2 vectors
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Vectors have different size");

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] -= vec.numbers[i];
    return *this;
}

Vectors Vectors::operator* (const Vectors& vec) const // scalar product
{
    Vectors result = *this;
    return result *= vec;
}

Vectors& Vectors::operator*= (const Vectors& vec) // scalar product
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Vectors have different size");
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] *= vec.numbers[i];
    return *this;
}

Vectors Vectors::operator* (const double num) const // product a vector and a number
{
    Vectors result = *this;
    return result *= num;
}

Vectors& Vectors::operator*= (const double num) // product a vector and a number
{
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] *= num;
    return *this;
}

Vectors Vectors::operator/ (const double num) const  // quotient a vector and a number
{
    Vectors result = *this;
    return result /= num;
}

Vectors& Vectors::operator/= (const double num)  // quotient a vector and a number
{
    if (num == 0)
        throw runtime_error("Division by zero");

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] /= num;
    return *this;
}

ostream& operator<< (ostream& os, Vectors& vec) // to print a column in the console
{
    for (int i = 0; i < vec.get_columns_count(); ++i)
    {
        os << vec.get_num()[i] << endl;
    }
    return os;
}
