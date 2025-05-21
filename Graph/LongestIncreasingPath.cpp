class Solution {
public:
    int m, n;
    int memo[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                ans = max(ans, dfs(matrix, r, c));
        return ans;
    }
    int DIR[5] = {0, 1, 0, -1, 0};
    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (memo[r][c] != 0) return memo[r][c];
        int ans = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + DIR[i], nc = c + DIR[i+1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || matrix[nr][nc] <= matrix[r][c]) continue;
            ans = max(ans, dfs(matrix, nr, nc) + 1);
        }
        return memo[r][c] = ans;
    }
};

//dfs normal call would contain, check if we have solved it already, intialise the answer or any such thing and finally store the answer after performimg the required operation
// explore all the 4 direction, check if the new direction are valid, if they calculate the answer based on the another dfs call to the new index and adding 1, store the max of it.,
//store the answer in memo[r][c] = ans, before returning it
