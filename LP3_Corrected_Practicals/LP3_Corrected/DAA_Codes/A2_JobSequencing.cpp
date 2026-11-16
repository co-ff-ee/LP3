#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

int main() {
    int n;
    cout << "Enter number of jobs: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Number of jobs must be positive.\n";
        return 1;
    }

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter job id, deadline and profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        if (jobs[i].deadline < 0) {
            cout << "Deadline cannot be negative.\n";
            return 1;
        }
    }

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (const Job& job : jobs) maxDeadline = max(maxDeadline, job.deadline);
    maxDeadline = min(maxDeadline, n); // At most n jobs can be scheduled.

    vector<int> slots(maxDeadline + 1, -1);
    int totalProfit = 0;

    for (const Job& job : jobs) {
        for (int t = min(job.deadline, maxDeadline); t >= 1; --t) {
            if (slots[t] == -1) {
                slots[t] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Selected sequence: ";
    for (int t = 1; t <= maxDeadline; ++t)
        if (slots[t] != -1) cout << "J" << slots[t] << " ";
    cout << "\nMaximum profit = " << totalProfit << "\n";
    return 0;
}
