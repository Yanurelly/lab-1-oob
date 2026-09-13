#include <iostream>
#include <Windows.h>
#include "Liniyne_rivnyannya.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Liniyne_rivnyannya eq;

    eq.Read();
    eq.Display();
    eq.root();
    
    return 0;
}