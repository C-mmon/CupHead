int low = 1;
int high = n;
//we 
while (low < high) {
    int mid = low + (high - low) / 2;
    if (!isBadVersion(mid)) { 
        low = mid + 1; 
        //we will move to the right half of the array, with mid+1, because the current version is good.
    } else { 
        high = mid;
        // the current version can be a potential bad version, so we will move to the left half of the array
    }
}

return low;  // at this pointer, you can return low or high, they are the same.