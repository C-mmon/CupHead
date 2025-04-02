Binary Search Using recursion 
bool binarySearch(int mid, int low, int high, int target)
{ 
	if(low > high)
		return false;
	if(mid == target)
		return true;
	if(arr[mid] < target)
	//return is required because the return value has to propogate back to the caller
		return binarySearch(mid+1 + (high-mid+1)/2, mid+1, high, target);
	else
		return binarySearch(low+(mid-1-low)/2, low, mid-1, target);
}