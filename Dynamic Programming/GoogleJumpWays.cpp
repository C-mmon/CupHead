#include<bits/stdc++.h>
using namespace std;

int getPossibleWays(int n, vector<int>& dp) {
   if(n < 0) {
   	return 0;
   }
   if(n == 0) {
   	return 1;
   }
   if(dp[n] != -1) {
   	return dp[n];
   }
   return dp[n] = getPossibleWays(n - 2, dp) + 3 * getPossibleWays(n - 1, dp);
}

int main() {
   int n = 4;
   vector<int> dp(n + 1, -1);
   int result = getPossibleWays(n - 1, dp);
   cout<<result<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int getPossibleWays(int n) {
    // dp[i] = number of ways to reach position i
    vector<int> dp(n, 0);
    dp[0] = 1;  // Only one way to be at position 0 (starting point)

    for (int i = 1; i < n; ++i) {
        // From i-1 with +1 move (3 outcomes)
        dp[i] += 3 * dp[i - 1];
        // From i-2 with +2 move (1 outcome), if i >= 2
        if (i >= 2)
            dp[i] += dp[i - 2];
    }

    return dp[n - 1];  // Number of ways to reach position n-1
}

int main() {
    int n = 4;
    cout << getPossibleWays(n) << endl;
    return 0;
}
