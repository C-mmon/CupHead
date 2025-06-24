int findMissing(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check expected value
        if (arr[mid] == mid + 1) {
            // Missing is on the right
            left = mid + 1;
        } else {
            // Missing is on the left or at mid
            right = mid - 1;
        }
    }
    // Missing number is at position `left + 1`
    return left + 1;
}
