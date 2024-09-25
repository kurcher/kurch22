#include <iostream>
#include <vector>
#include <Windows.h>

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    // �� ����������� 0 � 1 �������� �������
    std::vector<int> S1 = { 0, 1, 0, 1, 1 };
    std::vector<int> S2 = { 1, 0, 0, 1, 0 };

    // ��������, �� ����������� ����� �������� �������
    if (S1.size() != S2.size()) {
        std::cout << "����������� ������ ���� �������� �������!" << std::endl;
        return 1;
    }

    //  ����������� ���� �������� XOR
    std::vector<int> R(S1.size());

    // ��������� �������� XOR ��� ������� ��������
    for (size_t i = 0; i < S1.size(); ++i) {
        R[i] = S1[i] ^ S2[i];  
    }

    
    std::cout << "����������� ����������� ���� XOR: ";
    for (int r : R) {
        std::cout << r << " ";
    }
    std::cout << std::endl;

    return 0;
}
