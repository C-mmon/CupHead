class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            for (int i = index + 1; i <= n; ++i) {
                if (dp[i])
                    continue;
                if (dict.find(s.substr(index, i - index)) != dict.end()) {
                    dp[i] = true;
                    if (i == n) {
                        return true;
                    }
                    q.push(i);
                }
            }
        }
        return false;
    }
};
