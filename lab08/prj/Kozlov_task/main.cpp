#include <iostream>
#include <iomanip>
#include <string>
#include "ModulesKozlov.h"

using namespace std;

string authorCopyright() {
    return "������� ��";
}

bool logicalExpression(char a, char b) {
    return a+5 >= b;
}

string decHexOutput(string name, int num) {
    stringstream output;
    output << "'" << name << "' � ���������: " << dec << num
                        << ",\t � ��������������: " << hex << num;
    return output.str();
}

int main()
{
    system("chcp 1251 & cls");

    int x, y, z;
    cout << "������ 3 �����: ";
    cin >> x >> y >> z;
    char a, b;
    cout << "������ 2 �������: ";
    cin >> a >> b;

    cout << endl << authorCopyright() << endl << endl;

    cout << "��������� �������� ������ " << a << "+5 >= " << b << " - "
         << boolalpha << logicalExpression(a, b) << endl << endl;

    cout << decHexOutput("x", x) << endl;
    cout << decHexOutput("y", y) << endl;
    cout << decHexOutput("z", z) << endl;
    cout << "��������� ������ � ������� s_calculation(): " << fixed << s_calculation(x, y, z) << endl;
}
