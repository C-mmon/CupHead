class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort all the intervals by time 
        sort(intervals.begin(), intervals.end());
        //store the answer
        vector <vector <int>> ans;
        //iterate over the intervals 
        for(int i=0;i < intervals.size();i++)
        {
            if(ans.empty() || (!ans.empty() && (ans.back())[1] < intervals[i][0]))
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                int startTime  = (ans.back())[0];
                int endTime = (ans.back())[1];
                ans.pop_back();
                ans.push_back({startTime, max(intervals[i][1], endTime)});
            }
        }
        return ans;
    }
};
