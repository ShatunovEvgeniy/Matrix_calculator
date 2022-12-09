#ifndef OTHERS_FUNCTIONS_H
#define OTHERS_FUNCTIONS_H

#include <vector>

template <typename T>
std::vector<T> slicing(std::vector<T> const& v, int X, int Y); // slice of a vector

template <typename T>
std::vector<T> operator+ (const std::vector<T>& vec1, const std::vector<T>& vec2); // vectors concatenation

#endif // OTHERS_FUNCTIONS_H
