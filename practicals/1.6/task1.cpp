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
    // ������ ����� A
    int A;
    std::cout << "������ ���� ����� A: ";
    std::cin >> A;

    // ˳�������� ��� ������� ���
    int count_ones = 0;  // ������� �������
    int count_zeros = 0; // ������� ����

    // ��������� �� ������� ��� ����� A
    for (int i = 0; i < sizeof(A) * 8; ++i) {
        // ����������, �� � ���� 1 ��� 0
        if (A & (1 << i)) {
            count_ones++;
        }
        else {
            count_zeros++;
        }
    }

    
    std::cout << "ʳ������ �������: " << count_ones << std::endl;
    std::cout << "ʳ������ ����: " << count_zeros << std::endl;

    if (count_ones > count_zeros) {
        std::cout << "������� �����." << std::endl;
    }
    else if (count_ones < count_zeros) {
        std::cout << "���� �����." << std::endl;
    }
    else {
        std::cout << "ʳ������ ������� � ���� ��������." << std::endl;
    }

    return 0;
}
