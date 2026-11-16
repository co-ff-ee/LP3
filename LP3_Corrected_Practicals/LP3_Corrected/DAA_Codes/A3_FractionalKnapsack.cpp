#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight, ratio;
};

int main() {
    int n;
    cout << "Enter number of items: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Number of items must be positive.\n";
        return 1;
    }

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value and weight: ";
        cin >> items[i].value >> items[i].weight;
        if (items[i].weight <= 0 || items[i].value < 0) {
            cout << "Weight must be positive and value non-negative.\n";
            return 1;
        }
        items[i].ratio = items[i].value / items[i].weight;
    }

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    if (capacity < 0) {
        cout << "Capacity cannot be negative.\n";
        return 1;
    }

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double maxValue = 0.0;
    for (const Item& item : items) {
        if (capacity <= 0) break;
        if (item.weight <= capacity) {
            capacity -= item.weight;
            maxValue += item.value;
        } else {
            maxValue += item.value * (capacity / item.weight);
            capacity = 0;
        }
    }

    cout << "Maximum value = " << maxValue << "\n";
    return 0;
}
