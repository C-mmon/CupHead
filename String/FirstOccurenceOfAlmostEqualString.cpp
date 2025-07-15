class Solution {
public:
    int minStartingIndex(string s, string pattern) {
                auto z_function = [](const string& s) -> vector<int> {
            int n = s.size(), l = 0, r = 0;
            vector<int> z(n, 0);
            for (int i = 1; i < n; ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
            return z;
        };
              int n = s.size(), m = pattern.size();
        string pattern2(pattern.rbegin(), pattern.rend());
        string s2(s.rbegin(), s.rend());
        vector<int> z1 = z_function(pattern + s);
        vector<int> z2 = z_function(pattern2 + s2);
        for (int i = 0; i <= n - m; ++i)
            if (z1[m + i] + 1 + z2[n - i] >= m)
                return i;
        return -1;
    }
};
