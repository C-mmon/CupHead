class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> store;
        for (int i = 0; i < n; i++) {
            store.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(store.begin(), store.end()); 
        vector<int> dp(n + 1, 0); 
        for (int i = 1; i <=n; i++) {
            int endDay = get<0>(store[i-1]);
            int startDay = get<1>(store[i-1]);
            int profit = get<2>(store[i-1]);
            int left = 0, right= i-2,ans=-1;

            while (left <= right) {
                int mid = left + (right-left) / 2;
                int endCandidate = get<0>(store[mid]);
                if (endCandidate <= startDay) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            //if the answer is at index x, theen the ans+1 will be the dp index
            dp[i] = max(dp[i-1], profit + ((ans>=0) ? dp[ans+1]:0));
        }
            return dp[n];
        }
    };
