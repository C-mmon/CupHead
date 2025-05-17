class Solution {
public:
    void solve(int index, string curr, vector<string> &ans, int n, unordered_set<string> &dict, string &s){
        if(index == n){
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < n; i++){
            string temp = s.substr(index, i - index + 1);
            if(dict.count(temp)){
                string newCurr = curr.empty() ? temp : curr + " " + temp;
                solve(i + 1, newCurr, ans, n, dict, s);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> ans;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        solve(0, "", ans, n, dict, s);

        return ans;
    }
};
