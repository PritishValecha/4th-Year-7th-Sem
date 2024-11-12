#include <iostream>
using namespace std;

int fibIterative(int n) {
    if (n <= 1)
        return n;
    
    int fibPrev = 0, fibCurrent = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = fibPrev + fibCurrent;
        fibPrev = fibCurrent;
        fibCurrent = fib;
    }   
    return fib;
}

int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n-1) + fibRecursive(n-2);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int fibIt = fibIterative(n);
    cout << "Fibonacci(Iterative) number at position " << n << " is: " << fibIt << endl;

    int fibRe = fibRecursive(n);
    cout << "Fibonacci(Recursive) number at position " << n << " is: " << fibRe << endl;

    return 0;
}