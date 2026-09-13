#include "Liniyne_rivnyannya.h"
#include<iostream>
using namespace std;


void Liniyne_rivnyannya::Init(double a, double b) {
    if (a == 0) 
    {
        cout << "Коефіцієнт A не може бути 0" << endl;
        first = 1;
    }
    else 
    {
        first = a;
    }
    second = b;
}

void Liniyne_rivnyannya::Read() {
    cout << "A: ";
    cin >> first;

    while (first == 0) {
        cout << "A не може бути 0. Введіть ще раз: ";
        cin >> first;
    }

    cout << "B: ";
    cin >> second;
}

void Liniyne_rivnyannya::Display() {
    cout << "y = " << first << "x + " << second << endl;
}
    void Liniyne_rivnyannya::root() {
        if (second == 0) {
            cout << "Коефіцієнт B дорівнює 0, x = 0" << endl;
        }
        else {
            double x = -second / first;
            cout << "x = " << x << endl;
        }
    }

