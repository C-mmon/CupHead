class Solution {
public:
    vector<vector<int>> memo;
    int helper(vector<int>& nums, int searchSum, int index) {
        if (searchSum == 0) {
            return 1;
        }
        if (searchSum < 0 || index == nums.size()) {
            return 0;
        }
        if (memo[index][searchSum] != -1) {
            return memo[index][searchSum];
        }
        // we dont have the option for unlimited use, so use only once
        int include = helper(nums, searchSum - nums[index], index + 1);
        int exclude = helper(nums, searchSum, index + 1);
        return memo[index][searchSum] = include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //we need to take care of zeros
        int zeroCount = count(nums.begin(), nums.end(), 0);

        int sum = accumulate(nums.begin(), nums.end(), 0);
        //handle the corner case
        if ((target + sum) % 2 != 0 || abs(target) > sum)
            return 0;
        int searchSum = (target + sum) / 2;
        memo.resize(nums.size(), vector<int>(searchSum + 1, -1));
        vector<int> filtered;
        for (int num : nums)
            if (num != 0) filtered.push_back(num);
        int result=  helper(filtered, searchSum, 0);
        return result * (1 << zeroCount);
    }
};
