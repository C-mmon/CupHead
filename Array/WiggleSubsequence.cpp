class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int prevDiff = nums[1] - nums[0];
        int ans = (prevDiff != 0) ? 2 : 1;

        for (int i = 2; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((prevDiff <= 0 && diff > 0) || (prevDiff >= 0 && diff < 0)) {
                ans++;
                prevDiff = diff;
            }
        }
        return ans;
    }
};
