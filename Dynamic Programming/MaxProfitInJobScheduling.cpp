class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
               int n = startTime.size();
        vector<tuple<int, int, int>> jobs;

        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }

        // Step 1: Sort jobs by endTime
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b); // end time ascending
        });

        // Step 2: Prepare dp and endTime list
        vector<int> dp(n, 0);
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = get<1>(jobs[i]);
        }

        // Step 3: Fill dp
        for (int i = 0; i < n; ++i) {
            int start = get<0>(jobs[i]);
            int currProfit = get<2>(jobs[i]);

            // Binary search for last non-conflicting job
            int l = 0, r = i - 1;
            int idx = -1;

            while (l <= r) {
                int m = l + (r - l) / 2;
                if (ends[m] <= start) {
                    idx = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (idx != -1) {
                currProfit += dp[idx];
            }

            dp[i] = max(i > 0 ? dp[i - 1] : 0, currProfit);
        }

        return dp[n - 1];
    }
};
