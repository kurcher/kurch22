/**
 * Done by:
 * Student Name: Murai Yurii
 * Student Group: 123
 * Lab 1.5
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    {
        float a = 7.4;
        float b = 19.7;
        int c = 60;
        int d = 60;

        
        bool res = (!(a < b) && (!(c == d)));
        cout << "res: " << boolalpha << res << endl;
    }

    {
        int a = 17;
        int b = 17;
        float c = 8.3;
        float d = 54.6;

       
        bool res = (!(a == b) && (!(c == d)));
        cout << "res: " << boolalpha << res << endl;
    }

    return 0;
}
