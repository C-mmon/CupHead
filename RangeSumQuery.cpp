// C++ program for range greatest 
// pair sum query using segment tree 

#include <bits/stdc++.h> 
using namespace std; 

// Defining the node 
struct node { 
    int maxVal, greatestPSum; 
} st[100009]; 

// A utility function 
node util(node x, node y) 
{ 
    node ans; 

    // Find the maximum pair sum 
    ans.greatestPSum 
        = max(x.maxVal + y.maxVal, 
            max(x.greatestPSum, 
                y.greatestPSum)); 
    // Find the maximum value 
    ans.maxVal = max(x.maxVal, y.maxVal); 
    return ans; 
} 

// A utility function to get the 
// middle index from corner indexes. 
int getMid(int s, int e) 
{ 
    return s + (e - s) / 2; 
} 

/* A recursive function to get the 
greatest pair sum value in a given range 
of array indexes. Here: 

index --> Index of current node in the 
        segment tree. Initially 0 is 
        passed as root is always at index 0 
ss & se --> Starting and ending indexes 
            of the segment represented 
            by current node, i.e., st[index] 
qs & qe --> Starting and ending indexes 
            of query range */
node query(int ss, int se, int qs, 
        int qe, int index) 
{ 
    // If segment of this node is a part 
    // of given range, then return 
    // the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 

    node temp; 
    temp.maxVal = -1, 
    temp.greatestPSum = -1; 

    // If segment of this node 
    // is outside the given range 
    if (se < qs || ss > qe) 
        return temp; 

    // If a part of this segment 
    // overlaps with the given range 
    int mid = getMid(ss, se); 
    return util(query(ss, mid, qs, 
                    qe, 2 * index + 1), 

                query(mid + 1, se, qs, 
                    qe, 2 * index + 2)); 
} 

// Function to return the greatest pair 
// sum in the range from index 
// qs (query start) to qe (query end) 
node checkQuery(int n, int qs, int qe) 
{ 
    node temp; 
    temp.maxVal = -1, temp.greatestPSum = -1; 

    // Check for erroneous input values 
    if (qs < 0 || qe > n - 1 || qs > qe) { 
        cout << "Invalid Input"; 
        return temp; 
    } 

    return query(0, n - 1, qs, qe, 0); 
} 

// A recursive function that constructs 
// Segment Tree for array[ss..se]. 
// si is index of current node in segment tree 
node constructST(int arr[], int ss, 
                int se, int si) 
{ 
    // If there is one element in array, 
    // store it in current node of 
    // segment tree and return 
    if (ss == se) { 
        st[si].maxVal = arr[ss]; 
        st[si].greatestPSum = 0; 
        return st[si]; 
    } 

    // If there are more than one elements, 
    // then recur for left and right subtrees 
    int mid = getMid(ss, se); 
    st[si] = util(constructST(arr, ss, mid, 
                            si * 2 + 1), 

                constructST(arr, mid + 1, se, 
                            si * 2 + 2)); 
    return st[si]; 
} 

// Utility function to find the 
// greatest pair sum for the given 
// queries 
void operation(int arr[], int n, 
            int qs, int qe) 
{ 
    // Build segment tree from given array 
    constructST(arr, 0, n - 1, 0); 

    node ans = checkQuery(n, qs, qe); 

    // Print minimum value in arr[qs..qe] 
    cout << ans.greatestPSum << endl; 
} 

// Driver code 
int main() 
{ 
    int arr[] = { 1, 3, 2, 7, 9, 11 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    int L = 1; 
    int R = 4; 

    operation(arr, n, L, R); 

    return 0; 
}