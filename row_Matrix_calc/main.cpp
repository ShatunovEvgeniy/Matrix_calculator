#include <iostream>
#include "row.h"
using namespace std;

int main()
{
    vector<long double> i {1, 2, 3, 4, 5};
    vector<long double> h {1, 2, 3, 4, 5};
    Row row1(i);
    long double m = 3;
    Row row2(h);
    Row row3 = row1 / 10;
    row1 *= m;
    row3.get_row();
    cout<<'\n'<<row1[1]<<'\n';
    return 0;
}
