#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    
    const int CONST_VAL = 10 + 20; // R-вираз: обчислення результату 10 + 20

    
    int r_var = CONST_VAL * 2; // R-вираз: CONST_VAL помножити на 2

    
    int l_var;
    l_var = r_var; // L-вираз: присвоєння r_var змінній l_var

    // унарні операції, бітові операції, арифметичні операції, операція відношення
    int a = 5, b = 10, result;

    a = ++a; // унарний інкремент

    
    result = a & b; // побітове І

    
    result = result + 3; // додавання 3 до результату

    
    bool comparison = result >= 8; // чи більше або рівне 8

    
    cout << "CONST_VAL: " << CONST_VAL << endl;
    cout << "r_var: " << r_var << endl;
    cout << "l_var: " << l_var << endl;
    cout << "Result: " << result << endl;
    cout << "Comparison result: " << (comparison ? "True" : "False") << endl;

    return 0;
}
