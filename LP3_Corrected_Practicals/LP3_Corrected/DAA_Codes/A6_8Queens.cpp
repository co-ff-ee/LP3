#include <iostream>
#include <cstdlib>
using namespace std;

int board[8]; // board[row] = queen column; -1 means empty

bool isSafe(int row, int col) {
    for (int r = 0; r < 8; ++r) {
        if (r != row && board[r] != -1 &&
            (board[r] == col ||
             abs(board[r] - col) == abs(r - row)))
            return false;
    }
    return true;
}

bool solve(int row) {
    if (row == 8) return true;

    // The first queen is fixed by the user; do not move it.
    if (board[row] != -1) return solve(row + 1);

    for (int col = 0; col < 8; ++col) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solve(row + 1)) return true;
            board[row] = -1; // Backtrack
        }
    }
    return false;
}

int main() {
    int r, c;
    cout << "Enter row and column of first queen (0-7): ";
    if (!(cin >> r >> c) || r < 0 || r >= 8 || c < 0 || c >= 8) {
        cout << "Invalid position. Row and column must be 0 to 7.\n";
        return 1;
    }

    for (int i = 0; i < 8; ++i) board[i] = -1;
    board[r] = c;

    if (solve(0)) {
        cout << "One valid 8-Queens arrangement:\n";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j)
                cout << (board[i] == j ? "Q " : ". ");
            cout << "\n";
        }
    } else {
        cout << "No solution for this first queen position.\n";
    }
    return 0;
}
