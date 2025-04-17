//Given an array of positive integers, return the absolute difference between alpha and beta of the array.
//Alpha : No of times an element 'k' appears exactly 'k' consecutive times.
//Beta : No of times an element 'k' appears exactly 'k' consecutive times starting at index k. (1-based indexing)

// input: arr=[2,2,2,4,4,4,4,3,3,3,2,2]
//pseudo code 
vector <int> arr = {2,2,2,4,4,4,4,3,3,3,2,2};
int k=2; // k is the number of consecutive times an element appears
int alpha=0,beta=0;
int n=arr.size();
int count=1;
for(int i= n-1; i>=0;i--)
{
    if(arr[i] == arr[i-1])
    {
        count++;
    }
    else{
        count=1;//reset the count, if the number does not match the previous number
    }
    if(count == k) 
    {
        alpha++;
    }
    if(count == k && (i == k-1)) 
    {
        beta++;
    }
}