class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
                  int Max = amount + 1;
            vector<int> dp(amount + 1, Max);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.size(); j++) {
                    if (coins[j] <= i) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
        }
    };
    //in this question, you are given n coins and you need to find the minimum number of coins that can be used to make the amount.
    // Why greedy will not work?
    // Greedy approach doesn't go well with this question. Take this example. coins = [100, 90, 1] amount = 385
    // The greedy answer will be [3 * 100, 1 * 85], so all together 83
    // But a better combination will be [2 * 100, 2 * 90, 5 * 1], so 9.. hope you got the idea