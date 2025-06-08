#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &store, int index, int amount, vector<vector<int>> &memo) {
    if (amount == 0) {
        return 1;
    }
    if (amount < 0 || index == store.size()) {
        return 0;
    }
    if (memo[index][amount] != -1) {
        return memo[index][amount];
    }

    int include = helper(store, index, amount - store[index], memo);
    int exclude = helper(store, index + 1, amount, memo);

    return memo[index][amount] = include + exclude;
}

int countWaysToMakeAmount(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int countWays(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: There's 1 way to make amount 0 using any number of coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int index = n - 1; index >= 0; index--) {
        for (int amount = 0; amount <= target; amount++) {
        	//If we start from the bottom row (beyond last coin) and move upward (from last coin to first):
        	//When we process dp[index] row, we only need dp[index + 1] row and dp[index] itself.
            int include = (amount - coins[index] >= 0) ? dp[index][amount - coins[index]] : 0;
            int exclude = dp[index + 1][amount];

            dp[index][amount] = include + exclude;
        }
    }

    return dp[0][target];
}

int countWays(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: There's 1 way to make amount 0 using any number of coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    //prev will represent dp[index+1][amount ]
    vector <int> prev;
    prev[0] =1;

    for (int index = n - 1; index >= 0; index--) {
    	vector<int> curr(amount + 1, 0);
    	curr[0] = 1;
        for (int amount = 0; amount <= target; amount++) {
        	//If we start from the bottom row (beyond last coin) and move upward (from last coin to first):
        	//When we process dp[index] row, we only need dp[index + 1] row and dp[index] itself.
            int include = (amount - coins[index] >= 0) ? curr[amount - coins[index]] : 0;
            int exclude = prev[amount];

            curr[amount] = include + exclude;
        }
        prev = curr;
    }

    return prev[amount];
}

int countWaysToMakeAmount(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}
int main() {
    vector<int> store = {1, 2, 4};
    int amount = 11;
    vector<vector<int>> memo(store.size(), vector<int>(amount + 1, -1));
    cout << countWaysToMakeAmount(store, amount) << endl;
    return 0;
}
