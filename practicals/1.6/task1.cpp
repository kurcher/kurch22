//Murai Yurii
//Group 123
//Prac 1.6
// done


#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    // Задане число A
    int A;
    std::cout << "Введіть ціле число A: ";
    std::cin >> A;

    // Лічильники для кількості бітів
    int count_ones = 0;  // кількість одиниць
    int count_zeros = 0; // кількість нулів

    // Проходимо по кожному біту числа A
    for (int i = 0; i < sizeof(A) * 8; ++i) {
        // Перевіряємо, чи є бітом 1 або 0
        if (A & (1 << i)) {
            count_ones++;
        }
        else {
            count_zeros++;
        }
    }

    
    std::cout << "Кількість одиниць: " << count_ones << std::endl;
    std::cout << "Кількість нулів: " << count_zeros << std::endl;

    if (count_ones > count_zeros) {
        std::cout << "Одиниць більше." << std::endl;
    }
    else if (count_ones < count_zeros) {
        std::cout << "Нулів більше." << std::endl;
    }
    else {
        std::cout << "Кількість одиниць і нулів однакова." << std::endl;
    }

    return 0;
}
