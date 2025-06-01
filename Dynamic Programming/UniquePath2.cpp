class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
int m = obstacleGrid.size(), n = obstacleGrid[0].size();
vector<vector<int>> dp(m, vector<int>(n, 0));

// Initialize the starting point
dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

// Initialize the first column
for (int i = 1; i < m; ++i) {
    if (obstacleGrid[i][0] == 0) {
        dp[i][0] = dp[i-1][0];
    }
}

// Initialize the first row
for (int j = 1; j < n; ++j) {
    if (obstacleGrid[0][j] == 0) {
        dp[0][j] = dp[0][j-1];
    }
}

// Fill the DP table
for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
}

return dp[m-1][n-1];
    }
};
