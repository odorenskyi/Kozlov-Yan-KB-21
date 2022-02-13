#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesKozlov.h"

using namespace std;

int main()
{
    double input[10][3] = {0,    0,    0,
                           1,    0,    0,
                           0,    1,    0,
                           0,    0,    1,
                           -2.5, 3,    0,
                           -2.5, 0,    -3.12,
                           0,    4,    -2,
                           4.65, 1.1,  0,
                           2,    5,    6,
                           -11,  2.28, -9};
    double result[10] = {1,         4.141593, 1.718282,  0,         10.499504,
                         -9.973982, 54.59815, 16.563763, 149.12858, -33.653268};


    cout << "\t\tTestDriver of ModulesKozlov.a" << endl;
    for (int i = 0; i < 10; i++) {
        cout << resetiosflags(ios::fixed) << "TC_" << setfill('0') << setw(2) << i+1 << ":|" << setfill(' ');
        cout << "x = " << setw(5) << left << input[i][0];
        cout << "y = " << setw(5) << left << input[i][1];
        cout << "z = " << setw(5) << left << input[i][2];
        cout << fixed << "| - result: " << setw(10) << s_calculation(input[i][0], input[i][1], input[i][2]);
        cout << left << " - " << ((round(s_calculation(input[i][0], input[i][1], input[i][2])*1000000)/1000000.0 == result[i]) ? "passed" : "failed") << endl;
    }
    return 0;
}
