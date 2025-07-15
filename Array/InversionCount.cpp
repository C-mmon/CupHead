int mergeSort(vector <int> & arr, int left, int right)
{
int inv_count =0;
	if(i <  j)
	{
		int mid = low + (right-low)/2;
		int countLeftInversion += mergeSort(arr,left, mid);
		int countRightInversion += mergeSort(arr, mid+1, right);
		inv_count += merge(arr, l, m , r);
	}
	return inv_count;
}

int merge(vector <int> & arr, int left, int mid, int right)
{
	//what we need to return finally, is an array between left and right
	vector <int> temp (right-left+1);
	int leftPtr= l;
	int rightPtr = mid+1;
	int newArrayIndex=0;
	int inv_count =0;
	while(leftPtr <= mid && rightPtr <= right)
	{
		if(arr[leftPtr] <= arr[rightPtr])
		{
			temp[newArrayIndex++] = arr[leftPtr++];
			inv_count += (mid- i+1)

		}
		else
		{
			temp[newArrayIndex++] = arr[rightPtr++];
			//the
		}
	}
	while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    //now in the original array, we need to put the element back 
    for (int p = 0; p < temp.size(); ++p) {
        arr[left + p] = temp[p];
    }
    return inv_count;
}


int countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}


//a smaller number appears afte a larger number
// arr[i] > arr[j]  and i < j
// arr = [3, 1, 2]
// (3,1)  is inversion count 1
//  (3,2)

//The point of inversion count during merge step is that 
// we can see how many element which are larger 
// during the merge step, we can see how many elements from right half are jumping ahead 
// of left half

// that is during the merge sort, we would eventually know that a particular smaller number, 
// would be moving towards the left hand side, which is exactly what we want
