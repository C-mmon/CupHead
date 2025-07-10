#include <string>
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        vector<int> w1(26, 0);
        vector<int> w2(26, 0);
        for (char ch : word1) {
            w1[ch - 'a']++;
        }
        for (char ch : word2) {
            w2[ch - 'a']++;
        }
        for (int i = 0; i < word1.size(); i++) {
            if (w2[word1[i] - 'a'] == 0)
                return false;
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        for (int i = 0; i < 26; i++) {
            if (w1[i] != w2[i]) {
                return false;
            }
        }
        return true;
    }
};
