class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> grid(9, 0);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char ch = board[i][j];
                if(ch == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0';
                int val = 1 << (num-1);
                int gridCell = 3 * (i / 3) + (j / 3);
                if ((row[i] & val) || (col[j] & val) ||
                    (grid[gridCell] & val)) {
                    return false;
                }
                grid[gridCell] |= val;
                row[i] |= val;
                col[j] |= val;
            }
        }
        return true;
    }
};
