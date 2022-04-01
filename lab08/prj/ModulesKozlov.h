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

void writeDownOutput(std::string inputFilename, std::string outputFilename);

void appendDate(std::string inputFilename, std::string outputFilename);

void appendFuncRes(std::string outputFilename, double x, double y, double z, int b);

#endif // MODULESKOZLOV_H_INCLUDED
