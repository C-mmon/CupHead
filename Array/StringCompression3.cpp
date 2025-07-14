class Solution {
public:
    string compressedString(string word) {
        int count = 1;
        string ans = "";
        int n = word.size();
        for (int i = 1; i <=n; i++) {
            // count should be less than 9, because we are entereing over here
            // when we were at 8
            if (i < n && word[i] == word[i - 1] && count < 9) {
                count++;
            } else {
                ans += to_string(count) + word[i - 1];
                count = 1;
            }
        }

        return ans;
    }
};
