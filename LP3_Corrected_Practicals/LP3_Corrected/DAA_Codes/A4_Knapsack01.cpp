#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid number of items.\n";
        return 1;
    }

    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; ++i) {
        cout << "Enter weight and value of item " << i << ": ";
        cin >> weight[i] >> value[i];
        if (weight[i] < 0 || value[i] < 0) {
            cout << "Weight and value must be non-negative.\n";
            return 1;
        }
    }

    cout << "Enter capacity: ";
    cin >> capacity;
    if (capacity < 0) {
        cout << "Capacity cannot be negative.\n";
        return 1;
    }

    // dp[i][w] = maximum value using first i items and capacity w.
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i] <= w)
                dp[i][w] = max(dp[i][w],
                               value[i] + dp[i - 1][w - weight[i]]);
        }
    }

    cout << "Maximum value = " << dp[n][capacity] << "\n";
    return 0;
}
