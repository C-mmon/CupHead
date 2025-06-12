class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Found the target
            if (nums[mid] == target) return mid;

            // Determine which half is sorted
            if (nums[start] <= nums[mid]) {
                // Left half is sorted
                if (nums[start] <= target && target < nums[mid]) {
                    // Target lies in the left half
                    end = mid - 1;
                } else {
                    // Target lies in the right half
                    start = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    // Target lies in the right half
                    start = mid + 1;
                } else {
                    // Target lies in the left half
                    end = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
