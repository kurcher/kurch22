/**
 * Done by:
 * Student Name: Murai Yurii
 * Student Group: 123
 * Lab 1.4
 */

#include <iostream>

using namespace std;

int main() {
    // 1. ���� ������
    unsigned int wA;
    int nB;
    float fltC;

    // 2. ���� ���������
    unsigned int* pwA;
    int* pnB;
    float* pfltC;

    // 3. ���� ������������� ���������
    void* pV;

    // 4. ����������� ���������
    pwA = &wA;
    pnB = &nB;
    pfltC = &fltC;

    // 5. ����������� ������ ����� ���������
    *pwA = 10;
    *pnB = -25;
    *pfltC = 3.14f;

    // 6. ���������� ������ ������
    int sizewA = sizeof(wA);
    int sizenB = sizeof(nB);
    int sizefltC = sizeof(fltC);

    int sizepwA = sizeof(pwA);
    int sizepnB = sizeof(pnB);
    int sizepfltC = sizeof(pfltC);

    // 7. ��������� ����������
    cout << "����� ����� wA: " << sizewA << " ����" << endl;
    cout << "����� ����� nB: " << sizenB << " ����" << endl;
    cout << "����� ����� fltC: " << sizefltC << " ����" << endl;

    cout << "����� ��������� pwA: " << sizepwA << " ����" << endl;
    cout << "����� ��������� pnB: " << sizepnB << " ����" << endl;
    cout << "����� ��������� pfltC: " << sizepfltC << " ����" << endl;

    // 8. ����������� ������������� ���������
    pV = pwA;
    cout << "����������� ������� ����� pV ����� �� ������ pwA" << endl;

    return 0;
}