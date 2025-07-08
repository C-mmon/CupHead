class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len+1, false));
        dp[0][1] = true;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; ++j) {
                int diff = stones[i] - stones[j];
                if (diff < 0 || diff > len || !dp[j][diff]) {
                    continue;
                }
                dp[i][diff] = true;
                if (i == len - 1) {
                    return true;
                }
                if (diff - 1 >= 0) {
                    dp[i][diff - 1] = true;
                }
                if (diff + 1 <= len) {
                    dp[i][diff + 1] = true;
                }
            }
        }
        return false;
    }
};
