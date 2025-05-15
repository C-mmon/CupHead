class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
                int low = 0, high = arr.size() - 1;
        vector<int> store(2, -1);

        // Find first occurrence
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                high = mid; // Search left
            } else {
                low = mid + 1;
            }
        }

        // Check if target exists
        if (low >= arr.size() || arr[low] != target) return store;
        
        store[0] = low; // Store first occurrence

        // Find last occurrence
        high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2 + 1; // Bias mid towards the right
            if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid; // Move right
            }
        }

        store[1] = low; // Store last occurrence
        return store;
    }
};
