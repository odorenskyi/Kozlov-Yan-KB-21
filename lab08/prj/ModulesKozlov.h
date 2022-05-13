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

class ClassLab12_Kozlov {
public:
    ClassLab12_Kozlov(float len = 0, float wid = 0, float h = 0);
    float getVolume();
    float getLength() { return length; }
    float getWidth() { return width; }
    float getHeight() { return height; }
    void setLength(float);
    void setWidth(float);
    void setHeight(float);
private:
    float length, width, height;
};

ClassLab12_Kozlov::ClassLab12_Kozlov(float len, float wid, float h) {
    length = len;
    width = wid;
    height = h;
}

float ClassLab12_Kozlov::getVolume() {
    return length*width*height;
}

void ClassLab12_Kozlov::setLength(float val) {
    if (val >= 0) length = val;
    else length = 0;
}
void ClassLab12_Kozlov::setWidth(float val) {
    if (val >= 0) width = val;
    else width = 0;
}
void ClassLab12_Kozlov::setHeight(float val) {
    if (val >= 0) height = val;
    else height = 0;
}

#endif // MODULESKOZLOV_H_INCLUDED
