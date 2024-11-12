#include <iostream>
#include <vector>
using namespace std;

#define QUEEN 'Q'
#define EMPTY '.'

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check the column for any queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == QUEEN)
            return false;
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == QUEEN)
            return false;
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == QUEEN)
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(vector<string>& board, int row, int n) {
    // If all queens are placed, return true
    if (row >= n)
        return true;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = QUEEN; // Place the queen

            // Recursively place the rest of the queens
            if (solveNQueens(board, row + 1, n))
                return true;

            board[row][col] = EMPTY; // Backtrack
        }
    }

    return false; // No safe position found
}

int main() {
    int n, firstRow, firstCol;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    vector<string> board(n, string(n, EMPTY));

    // cout << "Enter the position of the first queen (row and column): ";
    // cin >> firstRow >> firstCol;

    // Place the first queen
    board[0][1] = QUEEN;

    // Solve the problem using backtracking
    if (solveNQueens(board, 1, n)) {
        cout << "Solution for the N-Queens problem:\n";
        for (const auto& row : board) {
            cout << row << endl;
        }
    } else {
        cout << "No solution exists for the given configuration." << endl;
    }

    return 0;
}
