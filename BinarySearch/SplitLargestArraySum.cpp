class Solution {
public:
    bool isPossible(vector<int>& nums, int maxSum, int k) {
        int count = 1; // at least one subarray
        int sum = 0;
        for (int num : nums) {
            if (num > maxSum) return false; // cannot split if any number exceeds maxSum
            if (sum + num > maxSum) {
                count++;
                sum = num;
                if (count > k) return false;
            } else {
                sum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;  // try smaller max sum
            } else {
                low = mid + 1;   // try larger max sum
            }
        }

        return ans;
    }
};
