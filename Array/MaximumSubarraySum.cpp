class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefixSum = nums[0];
        int maxSum =nums[0];
        for(int i=1; i< nums.size(); i++)
        {
            prefixSum = max(prefixSum+ nums[i], nums[i]);
            maxSum = max(maxSum, prefixSum);
        }
        return maxSum;
    }
};
