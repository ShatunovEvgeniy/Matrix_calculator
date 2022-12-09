#ifndef STREAMS_H
#define STREAMS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sqr_matrix.h"
using namespace std;

bool in_aviable(const std::vector<string>& v, const string& a);
void fill(istream& ist, vector<vector<long double>>& vec);
string get_first_string(istream& ist);

void write(Matrix m, ofstream& ofs);

void det(Matrix& m, ofstream& ofs);
void triangle(Matrix& m, ofstream& ofs);
void transpose(Matrix& m, ofstream& ofs);
void inverse(Matrix& m, ofstream& ofs);
void symmetric(Matrix& m, ofstream& ofs);
void skew_symmetric(Matrix& m, ofstream& ofs);

void Matrix_sum(Matrix& m1, Matrix& m2, ofstream& ofs);
void Matrix_diff(Matrix& m1, Matrix& m2, ofstream& ofs);
void Matrix_product(Matrix& m1, Matrix& m2, ofstream& ofs);
void Matrix_division(Matrix& m1, Matrix& m2, ofstream& ofs);

void calculate(const string& name1, const string& name2);

#endif // STREAMS_H
