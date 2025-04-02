int searchInRotatedArray(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;  // Found target

        // Check which half is sorted
        if (arr[low] <= arr[mid]) {  // Left half is sorted
            if (arr[low] <= target && target < arr[mid]) high = mid - 1;  // Target in left half
            else low = mid + 1;  // Target in right half
        } else {  // Right half is sorted
            if (arr[mid] < target && target <= arr[high]) low = mid + 1;  // Target in right half
            else high = mid - 1;  // Target in left half
        }
    }
    return -1;  // Target not found
}

//Search in Rotated Sorted Array 1
// In this question, you are given a rotated sorted array and a target value.
// The intuition behind this problem, upon checking the middle element, 
// we can determine which half of the array is sorted.
// If the left half is sorted, we can check if the target lies within that range.   
// If it does, we can search in that half; otherwise, we search in the other half.
// The same logic applies if the right half is sorted.
// The time complexity of this algorithm is O(log n) because we are halving the search space in each iteration

//In rotated sorted array 2, there can be duplicates.
if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
{
    low++;
    high--;
}
//consider a special case, where the leftmost and rightmost elements are equal to the middle element.
//example, [1, 0, 1, 1, 1] and target = 0
//here we cannot determine which half is sorted, so we need to increment low and decrement high.
// first half would be [1, 0, 1] and second half would be [1, 1]
//the original code will not work in this case, because we cannot determine which half is sorted.
//earlier we were relying on the fact that one half is sorted, but in this case, both halves are unsorted.
// So we need to increment low and decrement high.

//Find out how many times has an array been rotated, just
//the minimum element in the array will be the number of times the array has been rotated.


int findMin(vector <int> & nums)
{
    int left=0;
    int right= nums[size()-1];
    while(left <right)
    {
        int mid = left + (right - left) / 2;
        // we need to move towards the pivot side
        // if the left side is sorted, then we need to move towards the right side and vice versa
        if(arr[mid] > arr[right])
        {
            left = mid+1;
        }
        else if(arr[mid] < arr[right])
        {
            right = mid;
        }
        else if(arr[mid] == arr[right]) //we found a duplicate element
        {
            right--;
        }

    }
    return nums[left]; //we can either return left or right
}

// Find the minimum element in a rotated sorted array when duplicates are present.
int findMin(vector<int>& nums) {
    int left=0;
int right= nums.size()-1;
while(left <right)
{
int mid = left + (right - left) / 2;
// we need to move towards the pivot side
// if the left side is sorted, then we need to move towards the right side and vice versa
if(nums[mid] == nums[right])
{
right--;
}
if(nums[mid] > nums[right])
{
left = midW1;
}
else if(nums[mid] < nums[right])
{
right = mid;
}

}
return nums[left]; //we can either return left or right


//Find how many time arry has been rotated.
//Simply find the index of the minimum element in the rotated sorted array.