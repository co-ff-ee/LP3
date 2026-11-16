#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Enter n and k (0 <= k <= n <= 67): ";
    if (!(cin >> n >> k) || n < 0 || k < 0 || k > n || n > 67) {
        cout << "Invalid input. Use 0 <= k <= n <= 67.\n";
        return 1;
    }

    // Pascal's triangle using one-dimensional dynamic programming.
    // Update backwards so previous-row values are not overwritten.
    vector<unsigned long long> C(k + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j >= 1; --j)
            C[j] = C[j] + C[j - 1];
    }

    cout << "C(" << n << "," << k << ") = " << C[k] << "\n";
    return 0;
}
