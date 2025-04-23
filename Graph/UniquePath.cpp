    int uniquePaths(int m, int n) {
              vector<vector<int>> dp(m, vector<int>(n, 1));
      //need to understand why dp[i][j] is set to 1, ideally we should be only filling 0th row and 0th column, but its fine and faster way
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
