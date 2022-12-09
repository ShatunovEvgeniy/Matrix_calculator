#include "streams.h"
#include "others_functions.h"
#include <iomanip>


bool in_aviable(const std::vector<string>& v, const string& a)
{
    for (string i : v)
    {
        if (a==i)
            return true;
    }
    return false;
}

void fill(istream& ist, vector<vector<long double>>& vec)
{
    while (true)
    {
        vector<long double> a;
        ist>>a;
        if (a.size() == 0)
            break;
        vec.push_back(a);
        if (ist.eof())
            break;
    }
}

string get_first_string(istream& ist)
{
    string str;
    getline(ist, str);
    string word;
    for (char i: str)
    {
        if (!isspace(i))
            word += i;
    }
    return word;
}

void write(Matrix m, ofstream& ofs)
{
    ofs<<m;
}

void det(Matrix& m, ofstream& ofs)
{
    if (m.get_length() == m.get_width())
    {
        Sqr_matrix sq{m};
        long double det = sq.det();
        ofs<<det;
        ofs<<'\n'<<'\n';
    }
    else
        throw runtime_error("Not sqr matrix");
}

void triangle(Matrix& m, ofstream& ofs)
{
    if (m.get_length() == m.get_width())
    {
        Sqr_matrix sq{m};
        write(sq.triangle(), ofs);
    }
    else
        throw runtime_error("Not sqr matrix");
}

void transpose(Matrix& m, ofstream& ofs)
{
    Matrix t {m.T()};
    write(t, ofs);
}

void inverse(Matrix& m, ofstream& ofs)
{
    if (m.get_length() == m.get_width())
    {
        Sqr_matrix sq{m};
        write(sq.inverse(), ofs);
    }
    else
        throw runtime_error("Not sqr matrix");
}

void symmetric(Matrix& m, ofstream& ofs)
{
    if (m.get_length() == m.get_width())
    {
        Sqr_matrix sq{m};
        write(sq.symmetric(), ofs);
    }
    else
        throw runtime_error("Not sqr matrix");
}

void skew_symmetric(Matrix& m, ofstream& ofs)
{
    if (m.get_length() == m.get_width())
    {
        Sqr_matrix sq{m};
        write(sq.skew_symmetric(), ofs);
    }
    else
        throw runtime_error("Not sqr matrix");
}

void Matrix_sum(Matrix& m1, Matrix& m2, ofstream& ofs)
{
    Matrix m3 = m1 + m2;
    write(m3, ofs);
}

void Matrix_diff(Matrix& m1, Matrix& m2, ofstream& ofs)
{
    Matrix m3 = m1 - m2;
    write(m3, ofs);
}

void Matrix_product(Matrix& m1, Matrix& m2, ofstream& ofs)
{
    if (m2.get_length() == m2.get_width() || m2.get_length() == 1)
    {
        long double number = m2.get_num()[0];
        Matrix m3 = m1 * number;
        write(m3, ofs);
    }
    else
    {
        Matrix m3 = m1 * m2;
        write(m3, ofs);
    }
}

void Matrix_division(Matrix& m1, Matrix& m2, ofstream& ofs)
{
    if (m2.get_length() == m2.get_width() || m2.get_length() == 1)
    {
        long double number = m2.get_num()[0];
        Matrix m3 = m1 / number;
        write(m3, ofs);
    }
    else
        throw runtime_error("division by matrix");
}
//оператор ввода для вектор

void calculate(const string& name, const string& out_name){
    ifstream ist{name};     ///opening the input stream
    if (!ist)
        throw runtime_error("bad file");

    ofstream ofs{out_name};     //opening the output stream
    if (!ofs)
        throw runtime_error("Can't open output file");
    ofs<<fixed<<setprecision(2)<<setfill(' ')<<setw(6);


    vector<string> aviable {"det", "triangle", "transpose", "inverse", "symmetric", "skew_symmetric"};    //possible operations with a single matrix
    vector<string> znaki {"+", "-", "*", "/"};   //possible operations with two matrices

    string operation; ///to read the operation

    while (true)
    {
        while (ist.peek() == ' ' || ist.peek() == '\n')     //removing extra spaces
            ist.get();

        operation = get_first_string(ist);      //get the operation

        while (ist.peek() == ' ' || ist.peek() == '\n')     //removing extra spaces
            ist.get();

        if (in_aviable(aviable, operation))     //if the operation is unary
        {
            vector<vector<long double>> v;

            fill(ist, v);   //filling in the vector
            Matrix m{v};    //initialize the matrix with a vector

            if (operation == "det")
            {
                det(m, ofs);    //calculates determinant and writes in output file
            }

            else if (operation == "triangle")
            {
                triangle(m, ofs);   //converts the matrix to a triangular form and output
            }

            else if (operation == "transpose")
            {
                transpose(m, ofs);      //Transposes the matrix
            }
            else if (operation == "inverse")
            {
                inverse(m, ofs);    //
            }
            else if (operation == "symmetric")
            {
                symmetric(m, ofs);
            }
            else
            {
                skew_symmetric(m, ofs);
            }
        }

        else if (in_aviable(znaki, operation))  //if the operation is binarys
        {
            vector<vector<long double>> v1;
            vector<vector<long double>> v2;

            fill(ist, v1);      //filling in the vector

            while (ist.peek() == '\n' || ist.peek() == ' ')     //removing extra spaces
                ist.get();

            fill(ist, v2);      //filling in the vector

            Matrix m1{v1};
            Matrix m2{v2};

            if (operation == "+")
            {
                Matrix_sum(m1, m2, ofs);  //dum of 2 matrixes
            }

            else if (operation == "-")
            {
                Matrix_diff(m1, m2, ofs); //differences of 2 matrix
            }

            else if (operation == "*")
            {
                Matrix_product(m1, m2, ofs);  //product of 2 matrixes
            }
            else
            {
                Matrix_division(m1, m2, ofs);
            }
        }

        else
        {
            throw runtime_error("Bad input");  //If unexcepted input
        }

        while (ist.peek() == ' ' || ist.peek() == '\n')     //removing extra spaces
            ist.get();

        if (ist.eof())      //end of file
            break;
    }
}
