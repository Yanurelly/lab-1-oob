#pragma once
#include <string>
using namespace std;
class Fazzynumber {
private:
    double x;
    double el;
    double er;

public:
    void Init(double x_val, double el_val, double er_val);
    void Read();
    void Display() const;
    string toString() const;

    Fazzynumber Add(const Fazzynumber& B) const;
    Fazzynumber Subtract(const Fazzynumber& B) const;
    Fazzynumber Multiply(const Fazzynumber& B) const;
    Fazzynumber Inverse() const;
    Fazzynumber Divide(const Fazzynumber& B) const;
};