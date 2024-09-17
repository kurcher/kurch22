/**
 * Done by:
 * Student Name: Murai Yurii
 * Student Group: 123
 * Lab 1.4
 */

#include <iostream>

using namespace std;

int main() {
    // 1. Опис змінних
    unsigned int wA;
    int nB;
    float fltC;

    // 2. Опис вказівників
    unsigned int* pwA;
    int* pnB;
    float* pfltC;

    // 3. Опис нетипізованого вказівника
    void* pV;

    // 4. Ініціалізація вказівників
    pwA = &wA;
    pnB = &nB;
    pfltC = &fltC;

    // 5. Ініціалізація змінних через вказівники
    *pwA = 10;
    *pnB = -25;
    *pfltC = 3.14f;

    // 6. Визначення розміру змінних
    int sizewA = sizeof(wA);
    int sizenB = sizeof(nB);
    int sizefltC = sizeof(fltC);

    int sizepwA = sizeof(pwA);
    int sizepnB = sizeof(pnB);
    int sizepfltC = sizeof(pfltC);

    // 7. Виведення результатів
    cout << "Розмір змінної wA: " << sizewA << " байт" << endl;
    cout << "Розмір змінної nB: " << sizenB << " байт" << endl;
    cout << "Розмір змінної fltC: " << sizefltC << " байт" << endl;

    cout << "Розмір вказівника pwA: " << sizepwA << " байт" << endl;
    cout << "Розмір вказівника pnB: " << sizepnB << " байт" << endl;
    cout << "Розмір вказівника pfltC: " << sizepfltC << " байт" << endl;

    // 8. Ініціалізація нетипізованого вказівника
    pV = pwA;
    cout << "Нетипізована вказівна змінна pV вказує на адресу pwA" << endl;

    return 0;
}