#include <iostream>
#include <cmath>

using namespace std;

double s_calculation(double x, double y, double z) {
    double S = (M_PI * x + exp(abs(y)) - sqrt(abs(pow(z, 2) - y)));
    return S;
}
