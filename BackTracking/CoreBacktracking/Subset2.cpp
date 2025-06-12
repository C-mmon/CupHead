class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int start, vector<int>& temp) {
        ans.push_back(temp); // Every path is a valid subset

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: only allow the first occurrence at each level
            if (i != start && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);                    // Choose nums[i]
            backtrack(nums, i + 1, temp);               // Recurse with next index
            temp.pop_back();                            // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());                // Sort to group duplicates
        vector<int> temp;
        backtrack(nums, 0, temp);
        return ans;
    }
};
