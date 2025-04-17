#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Iterative solution using bit‑masking
int longestCommonSequence(const string& text1, const string& text2)
{
    int n = text1.length();
    int m = text2.length();
    int maxLen = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        string subseq;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                subseq.push_back(text1[i]);

        int i = 0, j = 0;
        while (i < (int)subseq.size() && j < m)
        {
            if (subseq[i] == text2[j]) ++i;
            ++j;
        }
        if (i == (int)subseq.size())
            maxLen = max(maxLen, (int)subseq.size());
    }
    return maxLen;
}

// Recursive solution without memoization
class RecursiveSolution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        return helper(text1, text2, 0, 0);
    }
private:
    int helper(const string& text1, const string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size())
            return 0;
        if (text1[i] == text2[j])
            return 1 + helper(text1, text2, i + 1, j + 1);
        else
            return max(helper(text1, text2, i + 1, j),
                       helper(text1, text2, i, j + 1));
    }
};

// Recursive solution with memoization
class MemoizedSolution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        dp.assign(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, 0, 0);
    }
private:
    vector<vector<int>> dp;
    int helper(const string& text1, const string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
            dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1);
        else
            dp[i][j] = max(helper(text1, text2, i + 1, j),
                           helper(text1, text2, i, j + 1));
        return dp[i][j];
    }
};

// Bottom-up Dynamic Programming solution
class DPSolution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};