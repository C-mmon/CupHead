class Solution {
public:
    int lcs(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s.size()][t.size()];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(), s.end());
        int len = lcs(t, s);
        return len;
    }
};
