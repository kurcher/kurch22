/**
 * Done by:
 * Student Name: Murai Yurii
 * Student Group: 123
 * Practice 1.5
 */
#include <iostream>
using namespace std;

int findFirstOccurrence(int A[], int n, int P) {
    for (int i = 0; i < n; i++) {
        if (A[i] == P) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int n, P;
    cout << "enter quantity of numbers ";
    cin >> n;
    int A[n];
    cout << "enter elements of sequence";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "enter P ";
    cin >> P;

    int index = findFirstOccurrence(A, n, P);
    if (index != -1) {
        cout << "index first P " << index << endl;
    }
    else {
        cout << "P is not found" << endl;
    }

    return 0;
}

