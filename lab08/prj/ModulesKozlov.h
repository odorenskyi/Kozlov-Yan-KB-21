#ifndef MODULESKOZLOV_H_INCLUDED
#define MODULESKOZLOV_H_INCLUDED

#include <string>

struct beaufort {
    int mark = -1;
    std::string description = "";
};

struct temperature {
    float Celcium = 0;
    float Fahrenheit = 32;
};

double s_calculation(double x, double y, double z);

beaufort beaufort_converter(float speed);

temperature avg_temperature(float data[]);

int bits_number(int number);

#endif // MODULESKOZLOV_H_INCLUDED
