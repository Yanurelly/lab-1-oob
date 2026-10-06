#include <iostream>
#include "Fazzynumber.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fazzynumber num1, num2;

    cout << "Перше нечітке число A" << endl;
    num1.Read();

    cout << "Друге нечітке число B" << endl;
    num2.Read();

    cout << "\nЧисло A: "; num1.Display();
    cout << "Число B: "; num2.Display();

    cout << "\nДодавання A + B: ";
    (num1 + num2).Display();

    cout << "Віднімання A - B: ";
    (num1 - num2).Display();

    cout << "Множення A * B: ";
    (num1 * num2).Display();

    cout << "Обернене число для A: ";
    num1.Inverse().Display();

    cout << "Ділення A / B: ";
    (num1 / num2).Display();

    cout << "\nРядкове представлення числа A: " << num1.toString() << endl;

    return 0;
}