#include <iostream>
#include<windows.h>
using namespace std;

class Base {
public:
    virtual void myname() {
        cout << "This is class Base" << endl;
    }
};

class DerA : virtual public Base {
public:
    void myname() {
        cout << "This is class DerA" << endl;
    }
};

class DerB : virtual public Base {
public:
    void myname() {
        cout << "This is class DerB" << endl;
    }
};

class DerAB : public DerA, public DerB {
public:
    void myname() {
        cout << "This is class DerAB" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Звичайні об'єкти" << endl;
    Base obj1;
    DerA obj2;
    DerB obj3;
    DerAB obj4;

    obj1.myname();
    obj2.myname();
    obj3.myname();
    obj4.myname();

    cout << "\nМасив покажчиків" << endl;
    Base* arr[4];

    arr[0] = new Base();
    arr[1] = new DerA();
    arr[2] = new DerB();
    arr[3] = new DerAB();

    for (int i = 0; i < 4; i++) {
        arr[i]->myname();
    }
    return 0;
}