#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <windows.h>

using namespace std;

struct PairAlg {
    double x;
    double y;
};

struct PairTrig {
    double radius;
    double angle;
};

class EmptyEx {};

class ParamEx {
public:
    double x, y;
    ParamEx(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

class InheritEx : public invalid_argument {
public:
    double x, y;
    InheritEx(double x, double y, const string& msg) : invalid_argument(msg) {
        this->x = x;
        this->y = y;
    }
};

PairTrig f1(PairAlg z) {
    if (z.x == 0) throw EmptyEx();

    PairTrig res;
    res.radius = sqrt(z.x * z.x + z.y * z.y);
    res.angle = atan(z.y / z.x);
    return res;
}

PairTrig f2(PairAlg z) throw() {
    PairTrig res;
    res.radius = sqrt(z.x * z.x + z.y * z.y);
    res.angle = (z.x == 0) ? 0 : atan(z.y / z.x);
    return res;
}

PairTrig f3(PairAlg z) throw(invalid_argument) {
    if (z.x == 0) throw invalid_argument("ділення на 0");

    PairTrig res;
    res.radius = sqrt(z.x * z.x + z.y * z.y);
    res.angle = atan(z.y / z.x);
    return res;
}

PairTrig f4(PairAlg z) throw(ParamEx, InheritEx) {
    if (z.x == 0 && z.y == 0) throw InheritEx(z.x, z.y, "x та y дорівнюють нулю");
    if (z.x == 0) throw ParamEx(z.x, z.y);

    PairTrig res;
    res.radius = sqrt(z.x * z.x + z.y * z.y);
    res.angle = atan(z.y / z.x);
    return res;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PairAlg z;
    cout << "x : "; // 0 шоб булп помилка
    cin >> z.x;
    cout << "y: ";
    cin >> z.y;
    cout << endl;

    try {
        f1(z);
    }
    catch (EmptyEx) {
        cout << "Порожній клас\n";
    }

    try {
        f2(z);
    }
    catch (...) {
        cout << "Виключення для ф-ї з специфікацією throw()\n";
    }

    try {
        f3(z);
    }
    catch (invalid_argument& e) {
        cout << "Стандартне виключення: " << e.what() << "\n";
    }

    try {
        f4(z);
    }
    catch (ParamEx& e) {
        cout << "Власне виключення як незалежний клас із полями-параметрами x = " << e.x << ", y = " << e.y << "\n";
    }
    catch (InheritEx& e) {
        cout << "Власне виключення як спадкоємець від стандартного: " << e.what() << "\n";
    }

    try {
        PairTrig res = f4(z);
        cout << "Без помилок R = " << res.radius << ", Кут = " << res.angle << "\n";
    }
    catch (...) {
        cout << "Помилка\n";
    }

    return 0;
}