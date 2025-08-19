class Solution {
public:

void helper(vector <int>& nums, int index, vector<vector <int>>& store)
{
    if(index== nums.size())
    {
        store.push_back(nums);
        return;
    }
    
    for(int i=index;i< nums.size(); i++)
    {

            swap(nums[index], nums[i]);
            helper(nums, index+1, store);
        swap(nums[index], nums[i]);


    }
    return ;
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> store;
        helper(nums, 0, store);
        sort(store.begin(), store.end());
        return store;
    }
};
