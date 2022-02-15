#include <iostream>
#include <iomanip>
#include <string>
#include "ModulesKozlov.h"

using namespace std;

string authorCopyright() {
    return "©Козлов Ян";
}

bool logicalExpression(char a, char b) {
    return a+5 >= b;
}

string decHexOutput(string name, int num) {
    stringstream output;
    output << "'" << name << "' в десятковій: " << dec << num
                        << ",\t в шістнадцятковій: " << hex << num;
    return output.str();
}

int main()
{
    system("chcp 1251 & cls");

    int x, y, z;
    cout << "Введіть 3 числа: ";
    cin >> x >> y >> z;
    char a, b;
    cout << "Введіть 2 символи: ";
    cin >> a >> b;

    cout << endl << authorCopyright() << endl << endl;

    cout << "Результат логічного виразу " << a << "+5 >= " << b << " - "
         << boolalpha << logicalExpression(a, b) << endl << endl;

    cout << decHexOutput("x", x) << endl;
    cout << decHexOutput("y", y) << endl;
    cout << decHexOutput("z", z) << endl;
    cout << "Результат виразу у функції  s_calculation(): " << fixed << s_calculation(x, y, z) << endl;
}
