#include <iostream>
#include <iomanip>
#include <string>
#include "ModulesKozlov.h"

using namespace std;

string authorCopyright() {
    return "© озлов ян";
}

bool logicalExpression(char a, char b) {
    return a+5 >= b;
}

string decHexOutput(string name, int num) {
    stringstream output;
    output << "'" << name << "' в дес€тков≥й: " << dec << num
                        << ",\t в ш≥стнадц€тков≥й: " << hex << num;
    return output.str();
}

int main()
{
    system("chcp 1251 & cls");

    int x, y, z;
    cout << "¬вед≥ть 3 числа: ";
    cin >> x >> y >> z;
    char a, b;
    cout << "¬вед≥ть 2 символи: ";
    cin >> a >> b;

    cout << endl << authorCopyright() << endl << endl;

    cout << "–езультат лог≥чного виразу " << a << "+5 >= " << b << " - "
         << boolalpha << logicalExpression(a, b) << endl << endl;

    cout << decHexOutput("x", x) << endl;
    cout << decHexOutput("y", y) << endl;
    cout << decHexOutput("z", z) << endl;
    cout << "–езультат виразу у функц≥њ s_calculation(): " << fixed << s_calculation(x, y, z) << endl;
}
