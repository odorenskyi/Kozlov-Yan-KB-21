#include <iostream>
#include <cmath>
#include <string>
#include <bitset>

using namespace std;

struct beaufort {
    int mark = -1;
    string description = "";
};

struct temperature {
    float Celcium = 0;
    float Fahrenheit = 32;
};

double s_calculation(double x, double y, double z) {
    double S = (M_PI * x + exp(abs(y)) - sqrt(abs(pow(z, 2) - y)));
    return S;
}

beaufort beaufort_converter(float speed) {
    speed = fabs(round(speed*10)/10);
    if (speed < 0.3) {
        return {0, "³�������� ����. ��� ��������� ����������. ����� ����� �������."};
    }
    if (speed <= 1.5) {
        return {1, "��� \"�����\". ������ �� ����������."};
    }
    if (speed <= 3.4) {
        return {2, "��� ������ ���������� ��������. ��������� �����. ������ ����������"};
    }
    if (speed <= 5.4) {
        return {3, "������ �����, ��������� ���� ����. �������� �������."};
    }
    if (speed <= 7.9) {
        return {4, "��������� ���� ���� �����. ³��� ����� ��� �� ������ ������."};
    }
    if (speed <= 10.7) {
        return {5, "��������� ����� ����. �� ��� �'��������� ����."};
    }
    if (speed <= 13.8) {
        return {6, "��������� ����� ����."};
    }
    if (speed <= 17.1) {
        return {7, "��������� ������� �������� �����. �� ��� ���������� ����, �������."};
    }
    if (speed <= 20.7) {
        return {8, "��������� ���� �����, � ����� ��� ����� ����."};
    }
    if (speed <= 24.4) {
        return {9, "������� ����������. ����� ������, ����� �����."};
    }
    if (speed <= 28.4) {
        return {10, "����� ����������. ������ ����������� � �������."};
    }
    if (speed <= 32.6) {
        return {11, "����� ����������."};
    }
    return {12, "���������� �� ����������."};
}

temperature avg_temperature(float data[]) {
    int array_size = sizeof(data)/sizeof(float);
    float average = 0;
    for (int i = 0; i < array_size; i++) {
        average += data[i];
    }
    average /= array_size;
    return {average, (average*9/5)+32};
}

int bits_number(int number){
    bitset<32> b_number{number};
    if (b_number[14]) {
        return b_number.count();
    }
    return 32 - b_number.count();
}
