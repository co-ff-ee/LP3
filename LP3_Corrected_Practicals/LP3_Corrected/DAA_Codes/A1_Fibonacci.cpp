#include <iostream>
using namespace std;

long long steps = 0;

long long fib(int n) {
    steps++;                         // Count recursive function calls
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter number of terms (0-30): ";
    if (!(cin >> n) || n < 0 || n > 30) {
        cout << "Enter n between 0 and 30.\n";
        return 1;
    }

    long long a = 0, b = 1;
    int iterativeSteps = 0;
    cout << "Iterative Fibonacci: ";
    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
        ++iterativeSteps;
    }
    cout << "\nIterative steps (loop iterations): " << iterativeSteps << "\n";

    steps = 0;
    cout << "Recursive Fibonacci: ";
    for (int i = 0; i < n; ++i) cout << fib(i) << " ";
    cout << "\nRecursive calls (total for all printed terms): " << steps << "\n";
    return 0;
}
