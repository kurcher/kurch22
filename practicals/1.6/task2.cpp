#include <iostream>
#include <vector>
#include <Windows.h>

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    // Дві послідовності 0 і 1 однакової довжини
    std::vector<int> S1 = { 0, 1, 0, 1, 1 };
    std::vector<int> S2 = { 1, 0, 0, 1, 0 };

    // Перевірка, що послідовності мають однакову довжину
    if (S1.size() != S2.size()) {
        std::cout << "Послідовності повинні бути однакової довжини!" << std::endl;
        return 1;
    }

    //  послідовність після операції XOR
    std::vector<int> R(S1.size());

    // Виконання операції XOR для кожного елемента
    for (size_t i = 0; i < S1.size(); ++i) {
        R[i] = S1[i] ^ S2[i];  
    }

    
    std::cout << "Результуюча послідовність після XOR: ";
    for (int r : R) {
        std::cout << r << " ";
    }
    std::cout << std::endl;

    return 0;
}
