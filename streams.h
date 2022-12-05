#ifndef STREAMS_H
#define STREAMS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sqr_matrix.h"
using namespace std;
bool in_aviable(const std::vector<string>& v, const string& a);
void write(Matrix m, const string& out_name);
void write_det(long double det, const string& out_name);
istream& operator>> (istream& is, vector<long double>& vector);
void fill(istream& ist, vector<vector<long double>>& vec);
string get_first_string(istream& ist);
void calculate(const string& name1, const string& name2);
#endif // STREAMS_H
