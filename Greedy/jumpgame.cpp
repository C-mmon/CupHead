class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0;

        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to
            //reach that particular index.

            //reach >= idx -> great, carry on. Otherwise,
            if(reach < idx) return false;

            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }

        //this means that you reached till the end of the array, wohooo!!
        return true;

    }
};
