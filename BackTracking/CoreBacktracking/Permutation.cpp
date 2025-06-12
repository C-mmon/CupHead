class Solution {
public:
vector <vector <int>> st;
void recursion(vector <int> & nums, int index)
{
    if(index == nums.size())
    {
        st.push_back(nums);
        return;
    }
    for(int i=index;i < nums.size();i++)
    {
        swap(nums[index], nums[i]);
        recursion(nums, index+1);
        swap(nums[index], nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        //we need to use the swap logic 
        //the logic must also use the backtracking '
        recursion(nums, 0);
        return st;
    }
};
