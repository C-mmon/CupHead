class Solution {
public:
    vector<vector<int>> store;
    void backtracking(vector<int>& candidates,int target, int startindex, vector <int> & temp)
    {
        if(target == 0)
        {
            store.push_back(temp);
            return;
        }
        if(target < 0)
        {
            return ;
        }

        for(int i=startindex; i < candidates.size(); i++)
        {
            if(i != startindex && candidates[i] ==  candidates[i-1])
            {
                continue;
            }

            if(candidates[i] > target)
            {
                break ;//the input is in the sorted format
            }
            temp.push_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        store.clear();
        backtracking(candidates, target, 0, temp);
        return store;
    }
};
