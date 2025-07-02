class Solution {
public:
    bool backtracking(vector<int>& matchsticks, vector<int>& store, int target,
                      int index) {
        if (index == matchsticks.size()) {
            return true;
        }
        int stick = matchsticks[index];
        for (int i = 0; i < store.size(); i++) {
            if (store[i] + stick > target) {
                continue;
            }
            store[i] += stick;
            if (backtracking(matchsticks, store, target, index + 1)) {
                return true;
            }
            store[i] -= stick;
            if(store[i] == 0)
            {
                break;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        vector<int> store(4, 0);
        sort(matchsticks.begin(), matchsticks.end());
        return backtracking(matchsticks, store, sum / 4, 0);
    }
};
