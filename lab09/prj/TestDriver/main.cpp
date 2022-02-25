#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <ModulesKozlov.h>

using namespace std;

int main()
{
    system("chcp 1251 & cls");
    double beaufort_input[10] = {-1, 0, 0.3, 1.49, 5.49, 7.95, 18.999, 27, 32.6, 32.7};
    int beaufort_result[10] = {1, 0, 1, 1, 4, 5, 8, 10, 11, 12};

    cout << "\t\tTestDriver of ModulesKozlov.a" << endl;
    cout << "\n\tFunction beaufort_converter(int speed):" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "TC_" << setfill('0') << setw(2) << i+1 << ":|";
        cout << "speed = " << setw(6) << left << beaufort_input[i];
        cout << "| - result: " << setfill(' ') << setw(2) << beaufort_converter(beaufort_input[i]).mark;
        cout << left << " - " << ((beaufort_result[i] == beaufort_converter(beaufort_input[i]).mark) ? "passed" : "failed");
        cout << " /*" << beaufort_converter(beaufort_input[i]).description << "*/" << resetiosflags(ios::left) << endl;
    }

    double avg_temperature_input[3][31] = {8, 5, 3, 3, 0, 0, 3, 1, 1, 1, 0, -1, -2, -1, -10, -15, -14, -15, -13, -9, 1, 4, 3, 7, 6, 2, 0, 0, 1, -3, -1,
                                           1, 1, 4, 3, 2, 0, 1, 2, 2, 2, 7, 1, 4, 5, 5, 3, 1, 0, -2, 2, 3, 2, 1, 2, 2, 3, 4, 4, 0, 2, 3,
                                           1, 1, 0, 0, -4, -5, -7, -9, -9, -7, -9, -3, 0, -2, -1, -1, 1, 2, -1, -4, -3, -4, -7, -6, -8, -5, -6, -5, 1, 3, 1};
    temperature avg_temperature_result[3] = {{6.5, 43.7}, {1, 33.8}, {1, 33.8}};

    float data[31];
    cout << "\n\tFunction avg_temperature(float data[]):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "TC_" << setfill('0') << setw(2) << i+1 << ":|";
        cout << "data = " << setfill(' ');
        for (int j = 0; j < 31; j++) {
            data[j] = avg_temperature_input[i][j];
            cout << setw(3) << avg_temperature_input[i][j] << (j == 30 ? "" : ",") << (j == 14 ? "\n\t      " : "");
        }
        cout << "| - result: " << setfill(' ') << setw(3) << avg_temperature(data).Celcium << ", " << avg_temperature(data).Fahrenheit;
        cout << left << " - " << ((avg_temperature_result[i].Celcium == avg_temperature(data).Celcium &&
                                   avg_temperature_result[i].Fahrenheit == avg_temperature(data).Fahrenheit) ? "passed" : "failed") << endl;
        cout << resetiosflags(ios::left);
    }

    int bits_number_input[10] = {6789629, 5461303, 3754105, 271990, 8363382, 6011525, 9082953, 9158136, 4235535, 1329098};
    int bits_number_result[10] = {16, 13, 11, 23, 15, 19, 23, 17, 24, 10};

    cout << "\n\tFunction bits_number(int number):" << endl;
    for (int i = 0; i < 10; i++) {
        string b_number = bitset<32>(bits_number_input[i]).to_string();
        cout << "TC_" << setfill('0') << setw(2) << i+1 << ":|";
        cout << "number = " << setw(7) << bits_number_input[i] << " - " << b_number.substr(0, 31-16) << " " << b_number[31-15] << " " << b_number.substr(31-14, 14);
        cout << "| - result: " << setfill(' ') << setw(2) << bits_number(bits_number_input[i]);
        cout << left << " - " << (bits_number_result[i] == bits_number(bits_number_input[i]) ? "passed" : "failed") << endl;
        cout << resetiosflags(ios::left);
    }

    return 0;
}
