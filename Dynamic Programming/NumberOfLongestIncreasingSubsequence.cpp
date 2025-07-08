class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
              int n = nums.size();
        if (n == 0) return 0;

        vector<pair<int, int>> dp(n, {1, 1}); // {length, count}
        int maxLisLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j].first + 1 > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    } else if (dp[j].first + 1 == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            maxLisLen = max(maxLisLen, dp[i].first);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i].first == maxLisLen) {
                count += dp[i].second;
            }
        }

        return count;
    }
};
