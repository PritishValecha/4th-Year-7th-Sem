#include <iostream>
#include <vector>

using namespace std;

#define Q 'Q'
#define E '.'

bool isSafe (int row, int col, vector <string>& board, int n) {
    for (int i=0; i<row; i++) {
        if (board[i][col] == Q)
            return false;
    }

    for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == Q)
            return false;
    }

    for (int i=row, j=col; i>=0 && j<n; i--, j++) {
        if (board[i][j] == Q)
            return false;
    }

    return true;
}

bool nQuuen(vector <string>& board, int row, int n) {
    if (row >= n)
        return true;

    for (int i=0; i<n; i++) {
        if (isSafe(row, i, board, n)) {
            board[row][i] = Q;

            if (nQuuen(board, row+1, n))
                return true;

            board[row][i] = E;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the board size : ";
    cin >> n;

    vector <string> board(n, string(n, E));

    if (nQuuen(board, 0, n)) {
        cout << "The solution is : " << endl;
        for (const auto& s: board) {
            cout << s << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}