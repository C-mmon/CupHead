class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // If current number is negative, swap min and max
            if (curr < 0)
                swap(minSoFar, maxSoFar);

            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            result = max(result, maxSoFar);
        }

        return result;
    }
};
