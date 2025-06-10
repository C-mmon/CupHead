class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector <vector <int>> dp(n, vector<int>  (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 && j==0)
                {
                    dp[i][j] = grid[0][0];
                }
                else
                {
              int down = 1e9, right = 1e9;
                    // Add path sum from the top cell if possible
                    if (i > 0) down = dp[i - 1][j] + grid[i][j];
                    // Add path sum from the left cell if possible
                    if (j > 0) right = dp[i][j - 1] + grid[i][j];
                    
                    // Choose the minimum path sum for current cell
                    dp[i][j] = min(down, right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};