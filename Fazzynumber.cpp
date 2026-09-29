#include "Fazzynumber.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

Fazzynumber::Fazzynumber() {
    x = 0.0;
    el = 0.0;
    er = 0.0;
}

Fazzynumber::Fazzynumber(double x_val, double el_val, double er_val) {
    x = x_val;
    el = el_val;
    er = er_val;
}

Fazzynumber::Fazzynumber(const Fazzynumber& other) {
    x = other.x;
    el = other.el;
    er = other.er;
}

Fazzynumber::~Fazzynumber() {
   
}

void Fazzynumber::Init(double x_val, double el_val, double er_val) {
    x = x_val;
    el = el_val;
    er = er_val;
}

void Fazzynumber::Read() {
    cout << "x: ";
    cin >> x;
    cout << "el: ";
    cin >> el;
    cout << "er: ";
    cin >> er;
}

void Fazzynumber::Display() const {
    cout << "( " << (x - el) << ", " << x << ", " << (x + er) << " )" << endl;
}

string Fazzynumber::toString() const {
    return "( " + to_string(x - el) + ", " + to_string(x) + ", " + to_string(x + er) + " )";
}

Fazzynumber Fazzynumber::Add(const Fazzynumber& B) const {
    Fazzynumber res;
    res.Init(x + B.x, el + B.el, er + B.er);
    return res;
}

Fazzynumber Fazzynumber::Subtract(const Fazzynumber& B) const {
    Fazzynumber res;
    res.Init(x - B.x, el + B.el, er + B.er);
    return res;
}

Fazzynumber Fazzynumber::Multiply(const Fazzynumber& B) const {
    Fazzynumber res;
    double new_x = x * B.x;
    double new_el = B.x * el + x * B.el - el * B.el;
    double new_er = B.x * er + x * B.er + er * B.er;
    res.Init(new_x, new_el, new_er);
    return res;
}

Fazzynumber Fazzynumber::Inverse() const {
    Fazzynumber res;
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

Fazzynumber Fazzynumber::Divide(const Fazzynumber& B) const {
    Fazzynumber res;
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