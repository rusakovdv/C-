#include <iostream>
#include <fstream>
#include "../6/StringM.h"

using namespace std;

void stringM() {
    StringM str("asdasf");
    cout << str << endl;

    cout << "Введите строку: ";
    cin >> str;
    cout << str << endl;
}

void open1() {
    char fname[15], c;
    cout << "Введите имя входного файла";
    cin >> fname;
    ifstream ifs(fname);
    if (!ifs)
        cout << "Не открыт входной файл " << fname;
    cout << "Введите имя выходного файла";
    cin >> fname;
    ofstream ofs(fname);
    if (!ofs)
        cout << "Не открыт выходной файл " << fname;

    while (ifs && ofs) {
        ifs.get(c);
        c = toupper(c);
        ofs.put(c);
    }
    cout << '.';
    cout << endl << "Выходной файл является копией входного файла в верхнем регистре" << endl;
}

void open2() {
    char name[12];
    fstream fin;
    cout << "Введите имя файла: ";
    cin >> name;

    fin.open(name, ios::in);
    if (fin) {
        cout << "Файл открыт " << name << endl;
        fin.close();
    } else {
        cout << "Не открыт выходной файл " << name << endl;
    }
}

void open3() {
    char *fname = "../8/8-fname.txt";
    fstream ofs(fname, ios::out);

    if (!ofs) {
        cout << "Файл " << fname << " уже существует" << endl;
        return;
    }
    ofs << "Эта строка записывается в новый файл. ";
    ofs.close();
    fstream fs;
    fs.open(fname, ios::out | ios::app);
    fs << " Сейчас к ней сделано добавление";
    fs.close();
    fstream ifs;
    ifs.open(fname, ios::in);
    if (ifs) {
        cout << "В старом файле содержится ..." << endl;
        char line[80];
        ifs.getline(line, sizeof(line));
        cout << line;
    } else {
        cout << "Ошибка при повторном открытии fname" << endl;
    }
}

int main() {
//    stringM();
//    open1();
//    open2();
    open3();

    return 0;
}