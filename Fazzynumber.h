#pragma once
#include <string>
using namespace std;
class Fazzynumber {
private:
    double x;
    double el;
    double er;

public:
    Fazzynumber();
    Fazzynumber(double x_val, double el_val, double er_val);
    Fazzynumber(const Fazzynumber& other);
    ~Fazzynumber();

    void Init(double x_val, double el_val, double er_val);
    void Read();
    void Display() const;
    string toString() const;

    Fazzynumber operator+(const Fazzynumber& B) const;
    Fazzynumber operator-(const Fazzynumber& B) const;
    Fazzynumber operator*(const Fazzynumber& B) const;
    Fazzynumber operator/(const Fazzynumber& B) const;
    Fazzynumber Inverse() const;
};