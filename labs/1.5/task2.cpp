#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251)
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU")
    
    const int CONST_VAL = 10 + 20; // R-�����: ���������� ���������� 10 + 20

    
    int r_var = CONST_VAL * 2; // R-�����: CONST_VAL ��������� �� 2

    
    int l_var;
    l_var = r_var; // L-�����: ��������� r_var ����� l_var

    // ����� ��������, ���� ��������, ���������� ��������, �������� ���������
    int a = 5, b = 10, result;

    a = ++a; // ������� ���������

    
    result = a & b; // ������� �

    
    result = result + 3; // ��������� 3 �� ����������

    
    bool comparison = result >= 8; // �� ����� ��� ���� 8

    
    cout << "CONST_VAL: " << CONST_VAL << endl;
    cout << "r_var: " << r_var << endl;
    cout << "l_var: " << l_var << endl;
    cout << "Result: " << result << endl;
    cout << "Comparison result: " << (comparison ? "True" : "False") << endl;

    return 0;
}
