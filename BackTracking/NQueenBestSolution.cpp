class Solution {
public:
    void backtracking(int row, int n, vector<string>& board, vector<int>& col, 
                      vector<int>& diagonal, vector<int>& antiDiagonal, vector<vector<string>>& result) {
        // Base case: if we've placed queens in all rows
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            int diagIndex = row - j + n - 1;      // Index for main diagonal
            int antiDiagIndex = row + j;         // Index for anti-diagonal

            // Check if placing a queen is valid
            if (col[j] || diagonal[diagIndex] || antiDiagonal[antiDiagIndex]) {
                continue;
            }

            // Place the queen
            board[row][j] = 'Q';
            col[j] = 1;
            diagonal[diagIndex] = 1;
            antiDiagonal[antiDiagIndex] = 1;

            // Recurse to the next row
            backtracking(row + 1, n, board, col, diagonal, antiDiagonal, result);

            // Backtrack: remove the queen
            board[row][j] = '.';
            col[j] = 0;
            diagonal[diagIndex] = 0;
            antiDiagonal[antiDiagIndex] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;       // To store all solutions
        vector<string> board(n, string(n, '.'));  // Initialize the board
        vector<int> col(n, 0);               // To track used columns
        vector<int> diagonal(2 * n - 1, 0);  // To track used main diagonals
        vector<int> antiDiagonal(2 * n - 1, 0);  // To track used anti-diagonals

        backtracking(0, n, board, col, diagonal, antiDiagonal, result);
        return result;
    }
};
