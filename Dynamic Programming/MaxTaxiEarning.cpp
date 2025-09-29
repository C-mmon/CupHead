long long maxTaxiEarnings(int n, vector<vector<int>>& A) {
    sort(A.begin(), A.end());                 // sorts by start, then end
    vector<long long> dp(n + 1, 0);          // dp[t] = best by time t
    int j = 0, m = (int)A.size();

    for (int i = 1; i <= n; ++i) {
        // carry forward if we stay idle until time i
        dp[i] = max(dp[i], dp[i - 1]);

        // take all rides starting at time i
        while (j < m && A[j][0] == i) {
            int s = A[j][0];
            int e = A[j][1];
            long long profit = (long long)(e - s) + (long long)A[j][2];
            if (e <= n) dp[e] = max(dp[e], dp[i] + profit);
            ++j;
        }
    }
    return dp[n];
}
