#ifndef STREAMS_H
#define STREAMS_H

#include "../Logic/sqr_matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool in_available(const std::vector<string>& v, const string& a); // if possible symbol
void fill(istream& ist, vector<vector<long double>>& vec); // fill vector<vector<long double>> from ostream
string get_first_string(istream& ist);

void write(Matrix m, ofstream& ofs); // print matrix in a file

void det(Matrix& m, ofstream& ofs); // find the determinant
void triangle(Matrix& m, ofstream& ofs); // make triangular form of a matrix
void transpose(Matrix& m, ofstream& ofs); // transpose the matrix
void inverse(Matrix& m, ofstream& ofs); // find inverse matrix
void symmetric(Matrix& m, ofstream& ofs); // find symmetric matrix
void skew_symmetric(Matrix& m, ofstream& ofs); // find skew symmetric matrix

void Matrix_sum(Matrix& m1, Matrix& m2, ofstream& ofs); // matrix + matrix
void Matrix_diff(Matrix& m1, Matrix& m2, ofstream& ofs); // matrix * matrix or matrix * number
void Matrix_product(Matrix& m1, Matrix& m2, ofstream& ofs); // / on number
void Matrix_division(Matrix& m1, Matrix& m2, ofstream& ofs); // choose the operation ans write result

void calculate(const string& name1, const string& name2); // choose an operation and write result

#endif // STREAMS_H
