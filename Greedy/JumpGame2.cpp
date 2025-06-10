class Solution {
public:
    int jump(vector<int>& nums) {
        int currentEnd =0;// The end of the range for the current jump
        int jump=0;
        int mxSoFar =0; 
             // We iterate up to the second to last element.
        // If we reach the last element, we don't need another jump from it.
        for(int i=0; i< nums.size()-1;i++)
        {
            mxSoFar = max(mxSoFar, nums[i]+i);
            // We iterate up to the second to last element.
            // If we reach the last element, we don't need another jump from it.
            if(currentEnd == i)
            {
                jump++;
                currentEnd= mxSoFar;
            }
        }
        return jump;
    }
};
