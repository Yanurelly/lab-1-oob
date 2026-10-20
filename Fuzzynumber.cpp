#include "pch.h"
#include "Fuzzynumber.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

Fuzzynumber::Fuzzynumber() {
    x = 0.0; el = 0.0; er = 0.0;
}

Fuzzynumber::Fuzzynumber(double x_val, double el_val, double er_val) {
    x = x_val; el = el_val; er = er_val;
}

Fuzzynumber::Fuzzynumber(const Fuzzynumber& other) {
    x = other.x; el = other.el; er = other.er;
}

Fuzzynumber::~Fuzzynumber() {}

void Fuzzynumber::Init(double x_val, double el_val, double er_val) {
    x = x_val; el = el_val; er = er_val;
}

void Fuzzynumber::Read() {
    cout << "x: "; cin >> x;
    cout << "el: "; cin >> el;
    cout << "er: "; cin >> er;
}

void Fuzzynumber::Display() const {
    cout << "(" << (x - el) << ", " << x << ", " << (x + er) << ")" << endl;
}

string Fuzzynumber::toString() const {
    return "(" + to_string(x - el) + ", " + to_string(x) + ", " + to_string(x + er) + ")";
}

Fuzzynumber Fuzzynumber::operator+(const Fuzzynumber& B) const {
    Fuzzynumber res;
    res.Init(x + B.x, el + B.el, er + B.er);
    return res;
}

Fuzzynumber Fuzzynumber::operator-(const Fuzzynumber& B) const {
    Fuzzynumber res;
    res.Init(x - B.x, el + B.el, er + B.er);
    return res;
}

Fuzzynumber Fuzzynumber::operator*(const Fuzzynumber& B) const {
    Fuzzynumber res;
    double new_x = x * B.x;
    double new_el = B.x * el + x * B.el - el * B.el;
    double new_er = B.x * er + x * B.er + er * B.er;
    res.Init(new_x, new_el, new_er);
    return res;
}

Fuzzynumber Fuzzynumber::Inverse() const {
    Fuzzynumber res;
    if (x > 0 && (x - el) > 0) {
        double new_x = 1.0 / x;
        double new_el = new_x - (1.0 / (x + er));
        double new_er = (1.0 / (x - el)) - new_x;
        res.Init(new_x, new_el, new_er);
    }
    else {
        cout << "[Помилка обернене число можливе лише для A > 0] ";
        res.Init(0, 0, 0);
    }
    return res;
}

Fuzzynumber Fuzzynumber::operator/(const Fuzzynumber& B) const {
    Fuzzynumber res;
    if (B.x > 0 && (B.x - B.el) > 0) {
        double new_x = x / B.x;
        double new_el = new_x - ((x - el) / (B.x + B.er));
        double new_er = ((x + er) / (B.x - B.el)) - new_x;
        res.Init(new_x, new_el, new_er);
    }
    else {
        cout << "[Помилка ділення можливе лише на B > 0] ";
        res.Init(0, 0, 0);
    }
    return res;
}