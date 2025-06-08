class Solution {
public:
//current index which we want to process
bool recursion(vector <int> kSubsetSum, int target, int index, vector <int> nums)
{
    if(index == nums.size())
    {
        for(int i=0; i< kSubsetSum.size(); i++)
        {
            if(kSubsetSum[i] != target)
            {
                return false;
            }
        }
        return true;
    }
    //now start iterating 
    int currNum = nums[index];
    for(int i=0; i<kSubsetSum.size() ; i++)
    {
        if(kSubsetSum[i] + currNum <= target)
        {
            //add the given number 
            kSubsetSum[i] += currNum;
            if(recursion(kSubsetSum, target, index+1, nums))
            {
                return true;
            }
            kSubsetSum[i] -= currNum;

        }
        
            // Prune duplicates
            if (kSubsetSum[i] == 0) break;
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        
        for(int i=0; i< nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum%k != 0)
        {
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        int targetSum = sum/k;
        //initialise k subset with zero 
        vector <int> kSubsetSum (k, 0);
        return recursion(kSubsetSum, targetSum, 0, nums);
    }
};
