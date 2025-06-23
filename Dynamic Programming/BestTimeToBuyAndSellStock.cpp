//at every state you have 2 option you can either hold a
//buy and sell is counted as 1 transaction
//Now lets understand let dp[i][j][k] be the state of ith day and j can be 0 or 1, 
// on the particular day, we have option to hold a stock or not hold a stock
// if we are holding a stock, then we choose to sell it or not sell
// if we are not holding the stock, we can choose to buy stock or not buy a stock/
//k represent the transaction 
//so the dp[i][j][k] 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
                int n = prices.size();
        if(n == 0 || k == 0)
            return 0;
        
        // dp[i][state][j]:
        // i - day index (0-indexed)
        // state: 0 for holding a stock, 1 for not holding stock
        // j - number of completed transactions (sell operations)
        // Initialize with INT_MIN to denote an impossible/invalid state.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, INT_MIN)));
        
        // Day 0 initialization.
        dp[0][0][0] = -prices[0];  // Started by buying stock on day 0.
        dp[0][1][0] = 0;           // Not holding any stock on day 0.
        
        // Process each day.
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // Not holding stock on day i:
                // Option 1: do nothing.
                dp[i][1][j] = dp[i-1][1][j];
                // Option 2: sell stock today.
                if(j > 0 && dp[i-1][0][j-1] != INT_MIN) {
                    dp[i][1][j] = max(dp[i][1][j], dp[i-1][0][j-1] + prices[i]);
                }
                
                // Holding stock on day i:
                // Option 1: do nothing.
                dp[i][0][j] = dp[i-1][0][j];
                // Option 2: buy stock today.
                // When buying, we use the not holding state from previous day with the same transaction count.
                if(dp[i-1][1][j] != INT_MIN) {
                    dp[i][0][j] = max(dp[i][0][j], dp[i-1][1][j] - prices[i]);
                }
            }
        }
        
        // The answer is the maximum profit on the last day when not holding any stock.
        int ans = 0;
        for (int j = 0; j <= k; j++){
            ans = max(ans, dp[n-1][1][j]);
        }
        return ans;
    }
};
