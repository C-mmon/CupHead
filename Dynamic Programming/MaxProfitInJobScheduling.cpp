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


//Extending the variation, now let's assume that we can only select only K jobs
A meeting can last multiple days (s[i] to e[i], inclusive).

You can attend at most k meetings per day, even if they overlap in time.

We are not finding the maximum total across the whole conference — instead, we want the maximum possible in a single day.
    //At the end of the day, all the matter is which meeting is active on that given day,


    Reasonig:
For each day D in 1...d 
    collect all meeting where s[i] <= d <=e[i]
    sort them knowledge gain ascending
    Take the top K value


   int ans = 0;
    for (int day = 1; day <= d; day++) {
        vector<int> available;
        for (int i = 0; i < n; i++) {
            if (s[i] <= day && day <= e[i]) {
                available.push_back(a[i]);
            }
        }
        sort(available.begin(), available.end(), greater<int>());
        int gain = 0;
        for (int i = 0; i < min(k, (int)available.size()); i++) {
            gain += available[i];
        }
        ans = max(ans, gain);
    }
    return ans;


