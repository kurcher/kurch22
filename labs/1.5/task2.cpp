//Done by: Murai Yurii
// 123
#include <iostream>
using namespace std;

int main() {

    const int CONSTA = 7;
    int B, E;
    B = 37;
    E = 7;
    float C;
    float* pC;
    pC = &C;
    *pC = 20;
    int D = 11;
    int F;

   

    bool  bRez = ((CONSTA & ~B) * (-C)) < (D * (E << sizeof F));
    cout << "Result : " << boolalpha << bRez;

    return 0;
}