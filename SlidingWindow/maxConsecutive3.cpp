//we need to find the maximum number of consecutive 1's in a binary array
//we can use sliding window technique to solve this problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxConsecutiveOnes(vector<int>& nums, int k) {
    int atmostZeros =k;
    int left=0;
    int right=0;
    int maxLength=0;
    while(right<nums.size()){
        //we can have atmost k zeros in the window 
        if(nums[right]==0){
            atmostZeros--;
        }
        if(atmostZeros<0)
        {
            //we need to shrink the window from left side
            while(atmostZeros<0){
                if(nums[left]==0){
                    atmostZeros++;
                }
                left++;
            }
        }
        maxLength=max(maxLength,right-left+1);
        right++;
    }
    return maxLength;