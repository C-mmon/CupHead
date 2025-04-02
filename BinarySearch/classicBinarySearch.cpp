bool binarySearch(vector<int>& arr, int searchElement) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == searchElement) {
            return true;
        }
        
        if (arr[mid] < searchElement) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return false;
}