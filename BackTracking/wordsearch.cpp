class Solution {
public:
    bool rec(int r, int c, int m, int n, int ind, vector<vector<char>>& board, string& word) {
        if (ind == word.size()) return true;
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[ind]) return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool down = rec(r + 1, c, m, n, ind + 1, board, word);
        bool up = rec(r - 1, c, m, n, ind + 1, board, word);
        bool left = rec(r, c - 1, m, n, ind + 1, board, word);
        bool right = rec(r, c + 1, m, n, ind + 1, board, word);

        board[r][c] = temp; // restore original character
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (rec(i, j, m, n, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};