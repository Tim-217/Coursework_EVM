#include "check.h"
int check_input_i() {
    int val;
    while (true) {
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Что-то вы не то ввели... Пожалуйста, введите целое число: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
    }
}
float check_input_f() {
    float val;
    while (true) {
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Что-то вы не то ввели... Пожалуйста, введите число: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
    }
}
void check_P1(float& p) {
    float p1 = 0.9;
    float p2 = 0.8;
    float p3 = 0.6;
    while (true){
        if (abs(p - p1) < 0.001 || abs(p - p2) < 0.001 || abs(p - p3) < 0.001)
            break;
        else {
            cout << "Что-то вы не то ввели... Введите вероятность заново: ";   
            p = check_input_f();
        }
    }
}
void check_P2(float& p) {
    float p1 = 0.9;
    float p2 = 0.7;
    float p3 = 0.5;
    while (true) {
        if (abs(p - p1) < 0.001 || abs(p - p2) < 0.001 || abs(p - p3) < 0.001) {
            break;
        }
        else {
            cout << "Что-то вы не то ввели... Введите вероятность заново: ";
            p = check_input_f();
        }
    }
}
void check_N(int& p) {
    while (true) {
        if (p == 2 || p == 5 || p == 10) {
            break;
        }
        else {
            cout << "Что-то вы не то ввели... Введите количество тактов заново: ";
            p = check_input_i();
        }
    }
}
void check_M(int& p) {
    while (true) {
        if (p == 4 || p == 8 || p == 16) {
            break;
        }
        else {
            cout << "Что-то вы не то ввели... Введите количество тактов заново: ";
            p = check_input_i();
        }
    }
}