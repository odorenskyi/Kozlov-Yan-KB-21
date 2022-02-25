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
        return {0, "Відсутність вітру. Дим піднімається прямовисно. Листя дерев нерухомі."};
    }
    if (speed <= 1.5) {
        return {1, "Дим \"пливе\". Флюгер не обертається."};
    }
    if (speed <= 3.4) {
        return {2, "Рух повітря відчувається обличчяс. Шелестить листя. Флюгер обертається"};
    }
    if (speed <= 5.4) {
        return {3, "Тріпоче листя, хитаються дрібні гілки. Майорять прапори."};
    }
    if (speed <= 7.9) {
        return {4, "Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу."};
    }
    if (speed <= 10.7) {
        return {5, "Хитаються великі гілки. На волі з'являються хвилі."};
    }
    if (speed <= 13.8) {
        return {6, "Хитаються великі гілки."};
    }
    if (speed <= 17.1) {
        return {7, "Хитаються невеликі стовбури дерев. На морі здіймаються хвилі, піняться."};
    }
    if (speed <= 20.7) {
        return {8, "Ламаються гілки дерев, і важко йти проти вітру."};
    }
    if (speed <= 24.4) {
        return {9, "Невеликі руйнування. Зриває покрівлі, руйнує димарі."};
    }
    if (speed <= 28.4) {
        return {10, "Значні руйнування. Дерева вириваються з корінням."};
    }
    if (speed <= 32.6) {
        return {11, "Великі руйнування."};
    }
    return {12, "Призводить до спустошень."};
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
