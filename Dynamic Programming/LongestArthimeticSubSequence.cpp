class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // the problem over here is, we might have many element
        //  for example. 6,2,4,6,10,8
        // dp[i][diff]: the length of the longest arithmetic subsequence ending
        // at index i with a common difference diff
        vector<unordered_map<int, int>> dp(nums.size());
        int maxAns = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    if (1 + dp[j][diff] > dp[i][diff]) {
                        dp[i][diff] = 1 + dp[j][diff];
                        maxAns = max(dp[i][diff], maxAns);
                    }
                } else {
                    dp[i][diff] = 2;
                    maxAns = max(dp[i][diff], maxAns);
                }
            }
        }
        return maxAns;
    }
};
