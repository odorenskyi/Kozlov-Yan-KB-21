#include <iostream>
#include <iomanip>
#include <fstream>
#include "ModulesKozlov.h"

using namespace std;

string tsDirPath = "./";
string testResPath = "TestResults.txt";

void testSetter(void (ClassLab12_Kozlov::*setter)(float), float (ClassLab12_Kozlov::*getter)(),
                ClassLab12_Kozlov obj, string tsPath = "TS.txt", string title = "setter()") {
    string buffer;
    ofstream resOut(testResPath, ios::app);
    if (resOut.is_open()) {
        ifstream setterTS(tsPath);
        if (setterTS.is_open()) {
            bool isLnBeg = true;
            resOut << "+" << setw(34) << left << setfill('-') << "" << setw(45)
                   << title << "+" << endl << setfill(' ');
            for (int i = 0; setterTS.tellg() != -1; i++) {
                if (isLnBeg) {
                    resOut << "|TC_" << left << setw(2) << i+1 << "|";
                    isLnBeg = false;
                }
                setterTS >> buffer;
                resOut << "input - " << setw(20) << buffer;
                if (buffer.find(',') != string::npos)
                    buffer[buffer.find(',')] = '.';
                for (int j = 0; j < (int)buffer.size(); j++) {
                    if ((buffer[j] < '0' || buffer[j] > '9') && buffer[j] != '.') {
                        buffer = "0";
                        break;
                    }
                }
                (obj.*setter)(stof(buffer));
                setterTS >> buffer;
                resOut << "output - " << setw(20) << (obj.*getter)();
                resOut << resetiosflags(ios::left);
                resOut << "|result - " << (((obj.*getter)() == stof(buffer)) ? "passed" : "failed") << "|" << endl;
                isLnBeg = true;
            }
            resOut << "+" << setw(80) << setfill('-') << "+" << endl << setfill(' ');
            setterTS.close();
        }
        else {
            cout << "Помилка при роботі з файлом " << tsPath << "." << endl;
        }
        resOut.close();
    }
    else {
        cout << "Помилка при роботі з файлом " << testResPath << "." << endl;
    }
}

void testVolume(float (ClassLab12_Kozlov::*getter)(), ClassLab12_Kozlov obj,
                string tsPath = "TS.txt", string title = "volume()") {
    string buffer;
    ofstream resOut(testResPath, ios::app);
    if (resOut.is_open()) {
        ifstream volumeTS(tsPath);
        if (volumeTS.is_open()) {
            bool isLnBeg = true;
            resOut << "+" << setw(34) << left << setfill('-') << "" << setw(45)
                   << title << "+" << endl << setfill(' ');
            for (int i = 0, j = 0; volumeTS.tellg() != -1; i++) {
                if (isLnBeg) {
                    resOut << "|TC_" << left << setw(2) << j+1 << "|";
                    isLnBeg = false;
                }
                volumeTS >> buffer;
                if (buffer.find(',') != string::npos)
                    buffer[buffer.find(',')] = '.';
                for (int j = 0; j < (int)buffer.size(); j++) {
                    if ((buffer[j] < '0' || buffer[j] > '9') && buffer[j] != '.') {
                        buffer = "0";
                        break;
                    }
                }
                switch (i%4) {
                case 0:
                    resOut << "l - " << setw(8) << buffer;
                    obj.setLength(stof(buffer));
                    break;
                case 1:
                    resOut << "w - " << setw(8) << buffer;
                    obj.setWidth(stof(buffer));
                    break;
                case 2:
                    resOut << "h - " << setw(8) << buffer;
                    obj.setHeight(stof(buffer));
                    break;
                case 3:
                    resOut << "|volume - " << setw(11) << (obj.*getter)();
                    resOut << resetiosflags(ios::left);
                    resOut << "|result - " << (((int)((obj.*getter)()*1000000) ==
                                              (int)(stof(buffer)*1000000)) ? "passed" : "failed") << "|" << endl;
                    isLnBeg = true;
                    j++;
                }
            }
            resOut << "+" << setw(80) << setfill('-') << "+" << endl << setfill(' ');
            volumeTS.close();
        }
        else {
            cout << "Помилка при роботі з файлом " << tsPath << "." << endl;
        }
        resOut.close();
    }
    else {
        cout << "Помилка при роботі з файлом " << testResPath << "." << endl;
    }
}

int main() {
    system("chcp 1251 & cls");
    string path = __FILE__;
    if (path.find("lab12\\prj\\") == string::npos) {
        for (int i = 0; i < 100; i++) {
            cout << "\a";
        }
        ofstream testRes(testResPath);
        if (testRes.is_open()) {
            testRes << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            testRes.close();
        }
        else {
            cout << "Помилка при роботі з файлом " << testResPath << "." << endl;
        }
        return -1;
    }

    ifstream mainFile("main.cpp");
    if (mainFile.is_open()) {
        tsDirPath = "../../TestSuite/";
        mainFile.close();
    }
    else {
        tsDirPath = "../TestSuite/";
    }

    testResPath = tsDirPath+testResPath;
    ofstream testRes(testResPath, ios::out);
    if (testRes.is_open()) testRes.close();

    ClassLab12_Kozlov aquarium;

    testSetter(&ClassLab12_Kozlov::setLength, &ClassLab12_Kozlov::getLength, aquarium, tsDirPath+"TS-1.txt", "setLength()");
    testSetter(&ClassLab12_Kozlov::setWidth, &ClassLab12_Kozlov::getWidth, aquarium, tsDirPath+"TS-1.txt", "setWidth()");
    testSetter(&ClassLab12_Kozlov::setHeight, &ClassLab12_Kozlov::getHeight, aquarium, tsDirPath+"TS-1.txt", "setHeight()");

    testVolume(&ClassLab12_Kozlov::getVolume, aquarium, tsDirPath+"TS-2.txt", "getVolume()");

    return 0;
}
