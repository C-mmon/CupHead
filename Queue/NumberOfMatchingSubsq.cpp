class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector < queue<pair<int, int>>> qVec(26);
        int res = 0;

        for (int i = 0; i < words.size(); i++) {
            char ch = words[i][0];
            qVec[ch - 'a'].push({i, 0});
        }
        for (char ch : s) {
            int qSize = qVec[ch - 'a'].size();
            for (int j = 0; j < qSize; j++) {
                pair<int, int> st = qVec[ch-'a'].front();
                qVec[ch-'a'].pop();
                if (st.second == words[st.first].size() - 1) {
                    res++;
                } else {
                    st.second++;
                    char t = words[st.first][st.second];
                    qVec[t - 'a'].push({st.first, st.second});
                }
            }
        }

        return res;
    }
};
