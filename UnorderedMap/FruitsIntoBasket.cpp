class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0;
        int ans=0;
        int right;
        for (right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;
            if (mp.size() == 3) {
                ans = max(ans, right - left);
                while (mp.size() != 2) {
                    mp[fruits[left]]--;
                    if (!mp[fruits[left]]) {
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};
