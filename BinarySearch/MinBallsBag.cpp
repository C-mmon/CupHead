class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        //Binary search bound 
        int left =1;
        int right= *max_element(nums.begin(), nums.end());
        while(left < right)
        {
            int middle  = (left+right)/2;
            //check if a valid distrubition is possible with current middle value 
            if(isPossible(middle, nums, maxOperations))
            {
                right=  middle;
            }
            else
            {
                left = middle+1;
            }
        }
        return left;
    }
    bool isPossible(int middle, vector <int> nums, int maxOperation)
    {
        int penalty = 0;
        for(auto i: nums)
        {
            int operation = ceil(i/ (double)middle)-1;
            penalty += operation;
            if(penalty > maxOperation)
            {
                return false;
            }
        }
        return true;
    }
};
