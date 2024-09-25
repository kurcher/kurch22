// Murai Yurii 
// 123 Group
// Lab 1.6
// doneS

#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    // Опис змінних типів int, float, unsigned short і їх ініціалізація згідно з вашим варіантом
    int a = -6306;               // з таблиці
    float b = 5.1e-1;            // з таблиці
    unsigned short c = 126;      // з таблиці

    // Опис змінних типів double, int, char
    double d;
    int e;
    char f;

    // Неявне приведення типів
    d = b;  // Неявне приведення float до double
    e = c;  // Неявне приведення unsigned short до int

    // Явне приведення типів
    d = static_cast<double>(a);  // явне приведення int до double
    f = static_cast<char>(c);    //   явне приведення unsigned short до char

    
    std::cout << "Значення змінних після ініціалізації та приведення типів:" << std::endl;
    std::cout << "a (int): " << a << std::endl;
    std::cout << "b (float): " << b << std::endl;
    std::cout << "c (unsigned short): " << c << std::endl;
    std::cout << "d (double): " << d << std::endl;
    std::cout << "e (int): " << e << std::endl;
    std::cout << "f (char): " << f << std::endl;

    return 0;
}
