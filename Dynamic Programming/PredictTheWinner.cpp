class Solution {
public:
int recursion(vector <vector <int>> memo, vector <int>& nums, int i, int j)
{
    //base case 
    //if its your turn and there is only one option left, you must take it  
    if(i == j)
    {
        return nums[i];
    }
    if(memo[i][j] !=  INT_MIN)
    {
        return memo[i][j];
    }
    int pickLeft = nums[i] - recursion(memo,nums, i+1, j);
    int pickRight = nums[j] - recursion(memo,nums, i, j-1);

    return memo[i][j] = max(pickLeft, pickRight);
}
    bool predictTheWinner(vector<int>& nums) {
        //let dp[i,j] be the maximum score between the range of i and j
        //we are using the dp to store the indexing there shall be no harm
        vector <vector <int>> memo (nums.size(), vector <int> (nums.size(), INT_MIN));
        return recursion(memo, nums, 0, nums.size()-1) >=0 ;
    }
};
