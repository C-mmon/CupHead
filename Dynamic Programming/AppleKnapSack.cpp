#include <bits/stdc++.h>
using namespace std;

//item can go to weight 1 or weight 2
//let dp[i][j] means maximum value achieve using the first i itemw 
// with weight limit j
int solve(vector<int>& weights, int i, int w1, int w2, vector<vector<vector<int>>>& dp) {
    if (i < 0) return 0; // no more items to consider

    if (dp[i][w1][w2] != -1) return dp[i][w1][w2];

    // Don't take item i
    int res = solve(weights, i - 1, w1, w2, dp);

    // Try putting it in suitcase 1
    if (weights[i] <= w1) {
        res = max(res, weights[i] + solve(weights, i - 1, w1 - weights[i], w2, dp));
    }

    // Try putting it in suitcase 2
    if (weights[i] <= w2) {
        res = max(res, weights[i] + solve(weights, i - 1, w1, w2 - weights[i], dp));
    }

    return dp[i][w1][w2] = res;
}
int main()
{
    vector <int > weights = {1, 2, 3, 4, 5};
    vector <int > values = {10, 15, 40, 30, 50};
    int w1 = 7;
    int w2 = 8;

    maxWeight(w1, weights, values);
    return 0;
}

Let dp[i][j][k] represent the maximum total weight you can achieve using the first i items, where:

j is the total weight in suitcase 1 (≤ w1)

k is the total weight in suitcase 2 (≤ w2

    int maxWeight(vector<int>& weights, int w1, int w2) {
    int n = weights.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w1 + 1, vector<int>(w2 + 1, 0)));

    for (int i = 1; i <= n; i++) {
        int wt = weights[i - 1];
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                // Don't take current item
                dp[i][j][k] = dp[i - 1][j][k];

                // Put in suitcase 1
                if (j >= wt) {
                    //at step i, we consider whether to include ith item or not
                    // if we decide to put the current item in suitciase 1
                    // we need previous capacity in suitcase in j-wt
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - wt][k] + wt);
                }

                // Put in suitcase 2
                if (k >= wt) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - wt] + wt);
                }
            }
        }
    }

    return dp[n][w1][w2];
}
But now lets think: for dp[i][j][k], we only ever refer to dp[i - 1][...][...] — that is,
only the previous layer i-1. We never need dp[i-2][...] or earlier.

vector<vector<int>> prev(w1+1, vector<int>(w2+1, 0));
vector<vector<int>> curr(w1+1, vector<int>(w2+1, 0));
int maxWeight(vector<int>& weights, int w1, int w2) {
    int n = weights.size();
    vector<vector<int>> prev(w1 + 1, vector<int>(w2 + 1, 0));
    vector<vector<int>> curr(w1 + 1, vector<int>(w2 + 1, 0));

    for (int idx = 0; idx < n; idx++) {
        int wt = weights[idx];

        // Start from scratch for this layer
        for (int i = 0; i <= w1; i++) {
            for (int j = 0; j <= w2; j++) {
                curr[i][j] = prev[i][j]; // Case 1: don't take the item

                // Case 2: try putting in suitcase 1
                if (i >= wt)
                    curr[i][j] = max(curr[i][j], prev[i - wt][j] + wt);

                // Case 3: try putting in suitcase 2
                if (j >= wt)
                    curr[i][j] = max(curr[i][j], prev[i][j - wt] + wt);
            }
        }

        // Move current layer to prev for next item
        prev = curr;
    }

    return prev[w1][w2];  // maximum combined weight with full capacities
}

int maxWeight(vector<int>& weights, int w1, int w2) {
    vector<vector<int>> dp(w1 + 1, vector<int>(w2 + 1, 0));
    for (int weight : weights) {
        vector<vector<int>> next = dp;  // copy current state
        for (int i = 0; i <= w1; i++) {
            for (int j = 0; j <= w2; j++) {
                // Option 1: put weight in suitcase 1
                if (i + weight <= w1)
                    next[i + weight][j] = max(next[i + weight][j], dp[i][j] + weight);

                // Option 2: put weight in suitcase 2
                if (j + weight <= w2)
                    next[i][j + weight] = max(next[i][j + weight], dp[i][j] + weight);
            }
        }
        dp = next;
    }

    // Find max packed weight
    int ans = 0;
    for (int i = 0; i <= w1; i++) {
        for (int j = 0; j <= w2; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
//lets assume the normal knapsack function is defined as follows

int normalKnapSack(int w1, vector <int>& weights, vector <int> &value, int n)
{
    if(n == 0 || w1 == 0)
    {
        return 0;
    }
    int notPick = normalKnapSack(w1, weights, value, n-1);
    int pick = INT_MIN;
    if(weights[n-1] <= w1)
    {
        pick = value[n-1]+ normalKnapSack(w1-weights[n-1], weights, value, n-1);
    }
    return max(pick, notPick);

}


    // Memoization table to store the results
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1))
int normalKnapSack(int w1, vector <int>& weights, vector <int> &value, int n)
{
    if(n == 0 || w1 == 0)
    {
        return 0;
    }

    if(memo[n][w1] != -1)
    {
        return memo[n][w1];
    }
    int notPick = normalKnapSack(w1, weights, value, n-1);
    int pick = INT_MIN;
    if(weights[n-1] <= w1)
    {
        pick = value[n-1]+ normalKnapSack(w1-weights[n-1], weights, value, n-1);
    }
    return memo[n][w1] =max(pick, notPick);

}
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            
            // If there is no item or the knapsack's capacity is 0
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                int pick = 0;
                
                // Pick ith item if it does not exceed the capacity of knapsack
                if(wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    
                // Don't pick the ith item
                int notPick = dp[i - 1][j];
                
                dp[i][j] = max(pick, notPick);
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}
