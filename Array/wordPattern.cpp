class Solution {
public:
    bool wordPattern(string pattern, string s) {
                unordered_map<char, string> mp;
        unordered_map<string, char> reverseMp;
        istringstream iss(s);
        vector<string> words;
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            if (mp.count(c)) {
                if (mp[c] != w) return false;
            } else {
                if (reverseMp.count(w)) return false;
                mp[c] = w;
                reverseMp[w] = c;
            }
        }

        return true;
    }
};
