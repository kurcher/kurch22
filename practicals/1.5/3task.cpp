#include <iostream>
using namespace std;

void swapMinMax(int A[], int n) {
    int minIndex = 0, maxIndex = 0;

    
    for (int i = 1; i < n; i++) {
        if (A[i] < A[minIndex]) {
            minIndex = i;
        }
        if (A[i] > A[maxIndex]) {
            maxIndex = i;
        }
    }

    
    int temp = A[minIndex];
    A[minIndex] = A[maxIndex];
    A[maxIndex] = temp;
}

int main() {
    int n;
    cout << "enter quantity of elements ";
    cin >> n;
    int A[n];
    cout << "enter elements of sequence ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    swapMinMax(A, n);

    cout << "sequence after change ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
