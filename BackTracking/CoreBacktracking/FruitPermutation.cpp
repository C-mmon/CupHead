class Solution {
public:
    void backtrack(vector<string>& res, string& path, unordered_map<char, int>& freq, int total, char lastChar) {
        if (path.size() == total) {
            res.push_back(path);
            return;
        }

        for (auto& [ch, count] : freq) {
            if (count > 0 && ch != lastChar) {
                path.push_back(ch);
                freq[ch]--;

                backtrack(res, path, freq, total, ch);

                freq[ch]++;
                path.pop_back();
            }
        }
    }

    vector<string> arrangeFruits(vector<int>& nums) {
        unordered_map<char, int> freq;
        freq['M'] = nums[0];
        freq['O'] = nums[1];
        freq['A'] = nums[2];

        vector<string> res;
        string path;
        int total = nums[0] + nums[1] + nums[2];

        backtrack(res, path, freq, total, '#');
        return res;
    }
};
