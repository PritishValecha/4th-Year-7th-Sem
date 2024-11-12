#include <iostream>
using namespace std;

int fibIterative (int n) {
    if (n <= 1)
        return 1;

    int a = 0, b = 1, c = 0;
    for (int i=1; i<n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int fibRecursive(int n) {
    if (n <= 2)
        return 1;

    return fibRecursive(n-2) + fibRecursive(n-1);
}

int main() {
    int n;
    cout <<"Enter a number : ";
    cin >> n;
    int fibI = fibIterative(n);
    int fibR = fibRecursive(n);
    cout <<"Iterative : " << fibI << endl;
    cout << "Recursive : " << fibR;

    return 0;
}