class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) {
            return {};
        }
        unordered_map<int, int> mp;
        sort(changed.begin(), changed.end());
        // sort and process the smaller half first
        // the problem over here is if you try to pair 4 with 8, without any
        // order, we might miss the fact that 4 was actually the double part
        //  so we need to take care of that
        for (int i = 0; i < changed.size(); i++) {
            mp[changed[i]]++;
        }
        vector<int> res;
        //starting with every smaller element, we are forecfully gonna remove the next 2x element
        // now lets say this 2x element was a pair of 4x, then in our original array if it existed
        // then we would have 2 coppies of 2x, not one.
        for (auto num : changed) {
            if (mp[num] == 0)
                continue;

            if (mp[2 * num] == 0)
                return {};
            res.push_back(num);
            mp[num]--;
            mp[2 * num]--;
        }
        return res;
    }
};
