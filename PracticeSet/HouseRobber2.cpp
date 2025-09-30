class Solution {
public:

    int rob(vector<int>& nums) {
        //so the only difference is that if we have not robber house 1, we can append house 1 and calculate 
        //otherwise other test case we
        if(nums.size() ==1)
        {
            return nums[0];
        }
        else if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        auto robHouse = [&](int start, int end)
        {
            int previous1=0;
            int previous2=0;
            for(int i=start;i<=end;i++)
            {
                int curr = max(previous2+ nums[i] , previous1);
                previous2 = previous1;
                previous1 = curr;
            }
            return previous1;
        };

        int rob = max (robHouse(0, nums.size()-2), robHouse(1, nums.size()-1));
        return rob;
    }
};
