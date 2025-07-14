        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<vector<int>>> prefix(n, vector<vector<int>>(10, vector<int>(10, 0)));
        vector<vector<vector<int>>> suffix(n, vector<vector<int>>(10, vector<int>(10, 0)));
        vector<int> count(10, 0);

        // Build prefix
        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';

            if (i > 0)
                prefix[i] = prefix[i - 1];

            for (int a = 0; a < 10; ++a) {
                prefix[i][a][digit] += count[a];
            }
            count[digit]++;
        }

        // Reset count and build suffix
        fill(count.begin(), count.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            int digit = s[i] - '0';

            if (i < n - 1)
                suffix[i] = suffix[i + 1];

            for (int a = 0; a < 10; ++a) {
                suffix[i][digit][a] += count[a];
            }
            count[digit]++;
        }

        // Count palindromic subsequences of form a b c b a
        long long total = 0;
        for (int center = 2; center <= n - 3; ++center) {
            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    int leftCount = prefix[center - 1][a][b];
                    int rightCount = suffix[center + 1][b][a];
                    total = (total + 1LL * leftCount * rightCount) % MOD;
                }
            }
        }

        return static_cast<int>(total);
