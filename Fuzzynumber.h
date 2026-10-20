#pragma once
#include <string>

#ifdef FUZZYNUMBERDLL_EXPORTS
#define FUZZYNUMBER_API __declspec(dllexport)
#else
#define FUZZYNUMBER_API __declspec(dllimport)
#endif

using namespace std;
class FUZZYNUMBER_API Fuzzynumber {
private:
    double x;
    double el;
    double er;

public:
    Fuzzynumber();
    Fuzzynumber(double x_val, double el_val, double er_val);
    Fuzzynumber(const Fuzzynumber& other);
    ~Fuzzynumber();

    void Init(double x_val, double el_val, double er_val);
    void Read();
    void Display() const;
    string toString() const;

    Fuzzynumber operator+(const Fuzzynumber& B) const;
    Fuzzynumber operator-(const Fuzzynumber& B) const;
    Fuzzynumber operator*(const Fuzzynumber& B) const;
    Fuzzynumber operator/(const Fuzzynumber& B) const;
    Fuzzynumber Inverse() const;
};