It took me sometime to understand the second question, but this can be apparently done with dp.
10 likes I will make a video solution on this one.

I will put one statement for those who wants to understand what is happening in the question
the strength of your team is determined by weakest link.
You are on a mission to maximize the weakest link, there are different ways to reach the target which (n-1, n-1).
There might be different path which might be possible, but you need to select the path in which the weakest link, is maximum.

Now, let's say that I am on the cell (i,j) then there are two ways to arrive here (i-1,j) or (i,j-1)

take both possible paths, and for each, compute the new minimum after including the current cell. Choose the path that gives the better bottleneck
dp[i][j] = max( min(dp[i-1][j], matrix[i][j]), min(dp[i][j-1], matrix[i][j]) )

I have compressed it like this but for those who wants to break it down further, think like this, if we had taken the right path,
my current weakest link would be decided by the minimum of matrix[i][j] or the dp[i][j-1],
same thing applies for the downward path.

Now, eventually you would have calculated the value, from this point onward, just select the path which gives you the maximum.
`
dp[0][0] = matrix[0][0];

// Initialize the first row
for (int j = 1; j < n; ++j) {
    dp[0][j] = min(dp[0][j - 1], matrix[0][j]);
}

// Initialize the first column
for (int i = 1; i < m; ++i) {
    dp[i][0] = min(dp[i - 1][0], matrix[i][0]);
}

// Fill in the rest of the DP table
for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
        int fromAbove = min(dp[i - 1][j], matrix[i][j]);
        int fromLeft  = min(dp[i][j - 1], matrix[i][j]);
        dp[i][j] = max(fromAbove, fromLeft);
    }
}`
