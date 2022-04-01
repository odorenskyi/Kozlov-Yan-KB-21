#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <bitset>
#include <set>

using namespace std;

struct beaufort {
    int mark = -1;
    string description = "";
};

struct temperature {
    float Celcium = 0;
    float Fahrenheit = 32;
};

set<char> letters {'к', 'т', 'У', 'л', 'Й'};

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

string annotation() {
    return "---------------------------\n"
           "Розробник модуля: Ян Козлов\n"
           "ЦНТУ, Кропивницький, Україна\n"
           "2022\n"
           "---------------------------\n";
}

int countLetters(string text) {
    int counter = 0;
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'А' && text[i] <= 'Я') || (text[i] >= 'а' && text[i] <= 'я') ||
             text[i] == 'Ї' || text[i] == 'ї' || text[i] == 'Є' || text[i] == 'є' ||
             text[i] == 'Ґ' || text[i] == 'ґ') {
            counter++;
        }
    }
    return counter;
}

string modifiedText(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (letters.find(text[i]) != letters.end()) {
            text[i] = '?';
        }
    }
    return text;
}

string poem(string input) {
    if (countLetters(input)%2 == 0) {
        return "   Матері\n"
               "В хаті сонячній промінь косо\n"
               "На долівку ляга з вікна...\n"
               "Твої чорні шовкові коси\n"
               "Припорошила вже сивина.\n";
    }
    else {
        return "   Вклонися їй\n"
               "Коли малим ти вперше став на ноги -\n"
               "Яка ж то радість матері була!\n"
               "Від тихої колиски до порога\n"
               "Вона тебе за руку провела.\n";
    }
}

void writeDownOutput(string inputFilename, string outputFilename) {
    string inputText;
    ifstream input (inputFilename, ios::in);
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            inputText += line + '\n';
        }
        input.close();
    }
    else {
        cerr << "Помилка під час відкриття файлу " << inputFilename << endl;
        return;
    }
    ofstream output (outputFilename, ios::out);
    if (output.is_open()) {
        output << annotation();
        output << "Речення з файлу " << inputFilename
               << " з символами 'к', 'т', 'У', 'л' та 'Й', заміненими на '?':" << endl;
        output << modifiedText(inputText) << endl;
        output << "У файлі " << inputFilename << " міститься " << countLetters(inputText) << " літер." << endl;
        output << poem(inputText);
        output.close();
    }
    else {
        cerr << "Помилка під час відкриття файлу " << outputFilename << endl;
        return;
    }
}

void appendDate(string inputFilename, string outputFilename) {
    string inputText;
    time_t rawtime;
    ifstream input (inputFilename, ios::in);
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            inputText += line + '\n';
        }
        input.close();
    }
    else {
        cerr << "Помилка під час відкриття файлу " << inputFilename << endl;
        return;
    }
    ofstream output (outputFilename, ios::app);
    if (output.is_open()) {
        output << endl << "Непарні символи речення з файлу " << inputFilename << ": ";
        for (int i = 0; i < inputText.length(); i++) {
            if ((i+1)%2 != 0) {
                output << inputText[i];
            }
        }
        time(&rawtime);
        output << endl << "|Дата та час дозапису інформації: " << ctime(&rawtime) << endl;
        output.close();
    }
    else {
        cerr << "Помилка під час відкриття файлу " << outputFilename << endl;
        return;
    }
}

void appendFuncRes(string outputFilename, double x, double y, double z, int b) {
    ofstream output (outputFilename, ios::app);
    if (output.is_open()) {
        bitset<32> b_number{b};
        output << "s_calculation(" << x << ", " << y << ", " << z << ")=" << s_calculation(x, y, z) << endl;
        output << "Число " << b << " у двійковому записі: " << b_number << endl;
        output.close();
    }
    else {
        cerr << "Помилка під час відкриття файлу " << outputFilename << endl;
        return;
    }
}
