#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "ModulesKozlov.h"

#define TIMESTR_LEN 24

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    string inputFilenames[3];
    string outputFilenames[3];
    string expOutputFilenames[9];

    string inputTexts[3] {"Його Батьківщиною була Україна.",
                          "/..']'[;]/./243535091",
                          "12345 українська english."};

    double sInput[3][3] {2,   1, 3,
                         3.2, 0, 2,
                         0,   0, -3};
    int binInput[3] {329048534, 65535, 0};

    for (int i = 0; i < 3; i++) {
        inputFilenames[i] = "input" + to_string(i+1) + ".txt";
        ofstream input(inputFilenames[i], ios::out);
        input << inputTexts[i];
        input.close();
        outputFilenames[i] = "output" + to_string(i+1) + ".txt";

        for (int j = 0; j < 3; j++) {
            expOutputFilenames[i*3 + j] = "expectedOutputs/expOutput" +
                                          to_string(i+1) + "_" + to_string(j+1) + ".txt";
        }
    }

    /* Кодування файлів expOutput%_%.txt має бути змінене на ANSI */

    cout << "\t\tTestDriver of ModulesKozlov.a" << endl;
    cout << "\n\tFunction writeDownOutput(string inputFilename, string outputFilename):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "TC_" << setfill('0') << setw(2) << right << i+1 << ":|" << setfill(' ');
        cout << "inputFilename = " << setw(12) << left << inputFilenames[i]+", ";
        cout << "outputFilename = " << setw(12) << left << outputFilenames[i];
        writeDownOutput(inputFilenames[i], outputFilenames[i]);

        ifstream outFile (outputFilenames[i], ios::in);
        string output;
        string line;
        if (outFile.is_open()) {
            while (getline(outFile,line)) {
                output += line+'\n';
            }
            outFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << outputFilenames[i] << "'" << endl;
            return -1;
        }

        ifstream expOutFile (expOutputFilenames[i], ios::in);
        string expOutput;
        if (expOutFile.is_open()) {
            while (getline(expOutFile,line)) {
                expOutput += line+'\n';
            }
            expOutFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << expOutputFilenames[i] << "'" << endl;
            return -1;
        }

        cout << "| - result: " << left << ((output == expOutput) ? "passed" : "failed");
        cout << resetiosflags(ios::left) << endl;
    }

    cout << "\n\tFunction appendDate(string inputFilename, string outputFilename):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "TC_" << setfill('0') << setw(2) << right << i+1 << ":|" << setfill(' ');
        cout << "inputFilename = " << setw(12) << left << inputFilenames[i]+", ";
        cout << "outputFilename = " << setw(12) << left << outputFilenames[i];
        appendDate(inputFilenames[i], outputFilenames[i]);

        ifstream outFile (outputFilenames[i], ios::in);
        string output;
        string line;
        if (outFile.is_open()) {
            while (getline(outFile,line)) {
                output += line+'\n';
            }
            outFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << outputFilenames[i] << "'" << endl;
            return -1;
        }

        ifstream expOutFile (expOutputFilenames[3+i], ios::in);
        string expOutput;
        if (expOutFile.is_open()) {
            while (getline(expOutFile,line)) {
                expOutput += line+'\n';
            }
            expOutFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << expOutputFilenames[3+i] << "'" << endl;
            return -1;
        }

        int pos = output.length()-2-TIMESTR_LEN;
        string output1 = output.substr(0, pos);
        string output2 = output.substr(pos);
        string expOutput1 = expOutput.substr(0, pos);

        bool testResult = true;
        if (output1 == expOutput1) {
            bool isCorrectTime = true;
            for(int i = 0; i < output2.length() && isCorrectTime; i++) {
                //Www Mmm DD HH:MM:SS YYYY
                if (i == 8 || i == 9 ||
                    i == 11 || i == 12 || i == 14 || i == 15 || i == 17 || i == 18 ||
                    (i >= 20 && i <= 23)){
                    if (output2[i] < '0' || output2[i] > '9') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 1 || i == 2 || i == 5 || i == 6) {
                    if (output2[i] < 'a' || output2[i] > 'z') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 3 || i == 7 || i == 10 || i == 19) {
                    if (output2[i] != ' ') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 10 || i == 13 || i == 16) {
                    if (output2[i] != ':') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 0 || i == 4) {
                    if (output2[i] < 'A' || output2[i] > 'Z') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 24 || i == 25) {
                    if (output2[i] != '\n') {
                        testResult = false;
                    }
                }
            }
            if (testResult == true) {
                testResult = isCorrectTime;
            }
        }
        else {
            testResult = false;
        }

        cout << "| - result: " << left << (testResult ? "passed" : "failed");
        cout << resetiosflags(ios::left) << endl;
    }

    cout << "\n\tFunction appendFuncRes(string outputFilename, double x, double y, double z, int b):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "TC_" << setfill('0') << setw(2) << right << i+1 << ":|" << setfill(' ');
        cout << "outputFilename = " << setw(12) << left << outputFilenames[i]+", ";
        cout << "a = " << setw(11) << left << to_string(sInput[i][0])+", ";
        cout << "b = " << setw(11) << left << to_string(sInput[i][1])+", ";
        cout << "c = " << setw(11) << left << to_string(sInput[i][2])+", ";
        cout << "b = " << setw(10) << left << binInput[i];

        appendFuncRes(outputFilenames[i], sInput[i][0], sInput[i][1], sInput[i][2], binInput[i]);

        ifstream outFile (outputFilenames[i], ios::in);
        string output;
        string line;
        if (outFile.is_open()) {
            while (getline(outFile,line)) {
                output += line+'\n';
            }
            outFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << outputFilenames[i] << "'" << endl;
            return -1;
        }

        ifstream expOutFile (expOutputFilenames[6+i], ios::in);
        string expOutput;
        if (expOutFile.is_open()) {
            while (getline(expOutFile,line)) {
                expOutput += line+'\n';
            }
            expOutFile.close();
        }
        else {
            cerr << "Помилка при роботі з файлом '" << expOutputFilenames[6+i] << "'" << endl;
            return -1;
        }

        int pos = output.find("\n\n", output.find("\n\n", 0)+1);
        pos = output.find("\n\n", pos+TIMESTR_LEN+2);

        string output1 = output.substr(0, pos-TIMESTR_LEN);
        string output2 = output.substr(pos-TIMESTR_LEN, pos);
        string output3 = output.substr(pos);
        string expOutput1 = expOutput.substr(0, pos-TIMESTR_LEN);
        string expOutput3 = expOutput.substr(pos);

        bool testResult = true;
        bool isCorrectTime = true;
        if (output1 == expOutput1) {
             isCorrectTime = true;
            for(int i = 0; i < output2.length() && isCorrectTime; i++) {
                //Www Mmm DD HH:MM:SS YYYY
                if (i == 8 || i == 9 ||
                    i == 11 || i == 12 || i == 14 || i == 15 || i == 17 || i == 18 ||
                    (i >= 20 && i <= 23)){
                    if (output2[i] < '0' || output2[i] > '9') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 1 || i == 2 || i == 5 || i == 6) {
                    if (output2[i] < 'a' || output2[i] > 'z') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 3 || i == 7 || i == 10 || i == 19) {
                    if (output2[i] != ' ') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 10 || i == 13 || i == 16) {
                    if (output2[i] != ':') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 0 || i == 4) {
                    if (output2[i] < 'A' || output2[i] > 'Z') {
                        isCorrectTime = false;
                    }
                }
                else if (i == 24 || i == 25) {
                    if (output2[i] != '\n') {
                        testResult = false;
                    }
                }
            }
            if (testResult == true) {
                testResult = isCorrectTime;
            }
        }
        else {
            testResult = false;
        }
        if (testResult == true) {
            if (output3 != expOutput3) {
                testResult = false;
            }
        }

        cout << "| - result: " << left << (testResult ? "passed" : "failed");
        cout << resetiosflags(ios::left) << endl;
    }
    system("pause");
}
