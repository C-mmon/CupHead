class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // there are 1 to k values in the previous row
                for (int f = 1; f <= k; f++) {
                    // we can only fill those value
                    if (j >= f) {
                        dp[i][j] = (dp[i-1][j-f] + dp[i][j])% MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
