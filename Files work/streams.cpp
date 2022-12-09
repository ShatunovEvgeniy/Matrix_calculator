#include "streams.h"

bool in_aviable(const std::vector<string>& v, const string& a)
{
    for (string i : v)
    {
        if (a==i)
            return true;
    }
    return false;
}

istream& operator>> (istream& is, vector<long double>& vector)
{
    double ch {0};
    while (true)
    {
        while (is.peek() == ' ')
            is.get();
        if (is.peek() == '\n' || is.peek() == '\0' || is.eof())
        {
            is.get();
            break;
        }
        is>>ch;
        vector.push_back(ch);
    }
    return is;
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


void calculate(const string& name, const string& out_name){
    ifstream ist{name};
    if (!ist)
        throw runtime_error("bad file");
    ofstream ofs{out_name};
    if (!ofs)
        throw runtime_error("Can't open output file");

    vector<string> aviable {"det", "triangle", "transpose"};
    vector<string> znaki {"+", "-", "*"};

    string word;

    while (true)
    {
        while (ist.peek() == ' ' || ist.peek() == '\n')
            ist.get();

        word = get_first_string(ist);

        while (ist.peek() == ' ' || ist.peek() == '\n')
            ist.get();

        if (in_aviable(aviable, word))
        {
            vector<vector<long double>> v;
            fill(ist, v);
            Matrix m{v};
            if (word == "det")
            {
                if (m.get_length() == m.get_width())
                {
                    Sqr_matrix sq{v};
                    long double det = sq.det();
                    ofs<<det;
                    ofs<<'\n';
                }
                else
                    throw runtime_error("Not sqr matrix");
            }
            if (word == "triangle")
            {
                if (m.get_length() == m.get_width())
                {
                    Sqr_matrix sq{v};
                    write(sq.triangle(), ofs);
                }
                else
                    throw runtime_error("Not sqr matrix");
            }
            else if (word == "transpose")
            {
                write(m.T(), ofs);
            }
        }

        else if (in_aviable(znaki, word))
        {
            vector<vector<long double>> v1;
            vector<vector<long double>> v2;

            fill(ist, v1);

            while (ist.peek() == '\n' || ist.peek() == ' ')
                ist.get();

            fill(ist, v2);

            Matrix m1{v1};
            Matrix m2{v2};

            if (word == "+")
            {
                m1 += m2;
                write(m1, ofs);
            }

            else if (word == "-")
            {
                m1 -= m2;
                write(m1, ofs);
            }

            else if (word == "*")
            {
                m1 *= m2;
                write(m1, ofs);
            }
        }

        else
        {
            throw runtime_error("Bad input");
        }

        while (ist.peek() == ' ' || ist.peek() == '\n')
            ist.get();
        if (ist.eof())
            break;
    }
}
