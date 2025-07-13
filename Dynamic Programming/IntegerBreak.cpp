class Solution {
    public int integerBreak(int n) {
        if (n <= 3) return n - 1;

        int[] dp = new int[n + 1];

        // Set base cases
        for (int i = 1; i <= 3; i++) {
            dp[i] = i;
        }

        for (int num = 4; num <= n; num++) {
            int ans = 0;
            for (int i = 2; i < num; i++) {
                ans = Math.max(ans, i * dp[num - i]);
            }
            dp[num] = ans;
        }

        return dp[n];
    }
}
