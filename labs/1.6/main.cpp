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
    // ���� ������ ���� int, float, unsigned short � �� ����������� ����� � ����� ��������
    int a = -6306;               // � �������
    float b = 5.1e-1;            // � �������
    unsigned short c = 126;      // � �������

    // ���� ������ ���� double, int, char
    double d;
    int e;
    char f;

    // ������ ���������� ����
    d = b;  // ������ ���������� float �� double
    e = c;  // ������ ���������� unsigned short �� int

    // ���� ���������� ����
    d = static_cast<double>(a);  // ���� ���������� int �� double
    f = static_cast<char>(c);    //   ���� ���������� unsigned short �� char

    
    std::cout << "�������� ������ ���� ����������� �� ���������� ����:" << std::endl;
    std::cout << "a (int): " << a << std::endl;
    std::cout << "b (float): " << b << std::endl;
    std::cout << "c (unsigned short): " << c << std::endl;
    std::cout << "d (double): " << d << std::endl;
    std::cout << "e (int): " << e << std::endl;
    std::cout << "f (char): " << f << std::endl;

    return 0;
}
