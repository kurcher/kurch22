#include <iostream>
#include <climits>
using namespace std;

int findMinPositive(int A[], int n) {
    int minPositive = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] < minPositive) {
            minPositive = A[i];
            found = true;
        }
    }

    if (found) {
        return minPositive;
    }
    else {
        return -1; 
    }
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

    int minPositive = findMinPositive(A, n);
    if (minPositive != -1) {
        cout << "minimal +  " << minPositive << endl;
    }
    else {
        cout << "+ elements arent exist" << endl;
    }

    return 0;
}
