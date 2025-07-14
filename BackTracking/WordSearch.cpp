class Solution {
public:
    bool solve(vector<vector<char>>& board, int n, int m, string& word, int i,
               int j, int index) {
        if (i >= n || j >= m || i < 0 || j < 0 || word[index] != board[i][j]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        char c1 = board[i][j];
        board[i][j] = '#';
        bool a = solve(board, n, m, word, i + 1, j, index + 1);
        if (a == true) {
            return true;
        }
        bool b = solve(board, n, m, word, i, j + 1, index + 1);
        if (b == true) {
            return true;
        }
        bool c = solve(board, n, m, word, i, j - 1, index + 1);
        if (c == true) {
            return true;
        }
        bool d = solve(board, n, m, word, i - 1, j, index + 1);
        if (d == true) {
            return true;
        }
        board[i][j] = c1;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, n, m, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
