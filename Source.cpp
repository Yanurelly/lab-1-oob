#include <iostream>
#include <windows.h>
using namespace std;
class Triad {
protected:
    int a, b, c;

public:
    Triad(int a1, int b1, int c1) {
        a = a1;
        b = b1;
        c = c1;
    }

    virtual void print() {
        cout << a << " " << b << " " << c << endl;
    }

    bool isEqual(Triad other) {
        if (a == other.a && b == other.b && c == other.c) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Time : public Triad {
public:
    Time(int h, int m, int s) : Triad(h, m, s) {}

    void print() {
        cout << a << ":" << b << ":" << c << endl;
    }

    bool operator==(Time other) {
        return (a == other.a && b == other.b && c == other.c);
    }

    bool operator!=(Time other) {
        return !(*this == other);
    }

    bool operator<(Time other) {
        int time1 = a * 3600 + b * 60 + c;
        int time2 = other.a * 3600 + other.b * 60 + other.c;
        return time1 < time2;
    }

    bool operator>(Time other) {
        int time1 = a * 3600 + b * 60 + c;
        int time2 = other.a * 3600 + other.b * 60 + other.c;
        return time1 > time2;
    }

    bool operator<=(Time other) {
        return (*this < other) || (*this == other);
    }

    bool operator>=(Time other) {
        return (*this > other) || (*this == other);
    }
};

Triad process(Triad obj) {
    obj.print();
    return obj;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triad tr1(1, 2, 3);
    Triad tr2(1, 2, 3);

    cout << "Тріада 1: ";
    tr1.print();
    cout << "Тріада 2: ";
    tr2.print();

    cout << "Чи рівні тріади 1 - так, 0 - ні: " << tr1.isEqual(tr2) << endl;

    Time t1(10, 30, 0);
    Time t2(12, 15, 0);

    cout << "\nЧас 1: ";
    t1.print();
    cout << "Час 2: ";
    t2.print();

    cout << "t1 == t2: " << (t1 == t2) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;
    cout << "t1 < t2: " << (t1 < t2) << endl;
    cout << "t1 > t2: " << (t1 > t2) << endl;
    cout << "\nПідстановка:" << endl;
    Triad res1 = process(tr1);
    Triad res2 = process(t1);

    return 0;
}