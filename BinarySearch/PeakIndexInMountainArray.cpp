int low = 0;
int high = arr.size() - 1;

while (low < high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] < arr[mid + 1]) { 
        //the following code means that you are on the increasing slope of the mountain
        //so the peak must be further right, so you move the low pointer.
        low = mid + 1;  // Move to the right half
    } else { 
        // the following code indicates that you are on the decreasing side of the mountain
        high = mid;  
    }
}

return low;  // Return index instead of value
