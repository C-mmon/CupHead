class Solution {
public:
    void gen(int s, vector<int>& candidates, int target, vector<int>& a, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(a);
            return;
        }

        for (int i = s; i < candidates.size(); ++i) {
            if (i > s && candidates[i] == candidates[i - 1]) continue; 

            if (candidates[i] > target) break;

            a.push_back(candidates[i]);
            gen(i + 1, candidates, target - candidates[i], a, res);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        gen(0, candidates, target, current, res);
        return res;
    }
};
