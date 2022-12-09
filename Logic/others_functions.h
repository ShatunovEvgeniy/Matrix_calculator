#ifndef OTHERS_FUNCTIONS_H
#define OTHERS_FUNCTIONS_H

#include <vector>
#include <fstream>

std::istream& operator>> (std::istream& is, std::vector<long double>& vector);
template <typename T>
std::vector<T> slicing(std::vector<T> const& v, int X, int Y); // slice of a vector

<<<<<<< Updated upstream
template <typename T>
std::vector<T> operator+ (const std::vector<T>& vec1, const std::vector<T>& vec2); // vectors concatenation
=======
>>>>>>> Stashed changes

#endif // OTHERS_FUNCTIONS_H
