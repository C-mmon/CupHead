int low = 0;
int high = arr.size() - 1;

while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == searchElement) {
        return mid;
    }

    if (arr[mid] < searchElement) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
// in the scenario the target was not found
return low;