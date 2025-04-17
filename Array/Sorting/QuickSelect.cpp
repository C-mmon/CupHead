#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function (similar to QuickSort)
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right]; // Choosing last element as pivot
    int p = left;
    //we are interested in finding the top K element 
    //hence the quick select has to work with descbeding order
    //any element which is greater than pivot we are throwing them on left hand side

    for (int i = left; i < right; i++) {
        if (arr[i] >= pivot) {  // Sorting in descending order
            swap(arr[i], arr[p]);
            p++;
        }
    } 
   //swap pivot with small element at the end
    swap(arr[p], arr[right]);  // Move pivot to correct position
    return p;
}

// QuickSelect to find top K elements
void quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        
        if (pivotIndex == k - 1) return;  // Found top K elements
        else if (pivotIndex < k - 1) quickSelect(arr, pivotIndex + 1, right, k);
        else quickSelect(arr, left, pivotIndex - 1, k);
    }
}

// Function to get max K elements
vector<int> maxKElements(vector<int>& arr, int k) {
    int n = arr.size();
    quickSelect(arr, 0, n - 1, k);
    return vector<int>(arr.begin(), arr.begin() + k);
}

// Main function
int main() {
    vector<int> arr = {3, 1, 5, 12, 2, 11, 7};
    int k = 3;
    
    vector<int> result = maxKElements(arr, k);
    
    cout << "Top " << k << " elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}