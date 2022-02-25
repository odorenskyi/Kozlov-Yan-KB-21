#include <iostream>
#include <conio.h>
#include <bitset>
#include "ModulesKozlov.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");
    int c = 0;
    while ((c = getch()) != 't' && c != 'T' && c != 'C') {
        switch (c) {
        case '7':
            putchar(c);
            cout << endl;
            cout << "s_calcuation():" << endl;
            double x, y, z;
            cout << "Enter x: ";
            cin >> x;
            cout << "Enter y: ";
            cin >> y;
            cout << "Enter z: ";
            cin >> z;
            cout << "Result of s_calculation(): " << s_calculation(x, y, z) << endl;
            break;
        case '5':
            putchar(c);
            cout << endl;
            cout << "beaufort_converter():" << endl;
            float speed;
            cout << "Enter speed: ";
            cin >> speed;
            cout << "Result of beaufort_converter(): " << beaufort_converter(speed).mark << ". " <<
                    beaufort_converter(speed).description << endl;
            break;
        case '4':
            putchar(c);
            cout << endl;
            cout << "avg_temperature():" << endl;
            float data[31];
            cout << "Enter the set of January temperature indicators (31): ";
            for (int i = 0; i < 31; i++) {
                cin >> data[i];
            }
            cout << "Result of avg_temperature(): " << avg_temperature(data).Celcium << " °C" << "\t" <<
                                                       avg_temperature(data).Fahrenheit << " °F" << endl;
            break;
        case '3':
            putchar(c);
            cout << endl;
            cout << "bits_number():" << endl;
            int number;
            cout << "Enter integer number: ";
            cin >> number;
            string b_number = bitset<32>(number).to_string();
            cout << b_number.substr(0, 31-16) << "|" << b_number[31-15] << "|" << b_number.substr(31-14, 14) << endl;
            cout << "Result of bits_number(): " << bits_number(number) << endl;
            break;
        }

    }
    putchar(c);
}
