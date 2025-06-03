class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
            int result = 0;
        vector<queue<pair<int, int>>> q(26);
        for(int i = 0; i < words.size(); i++)
        {
            q[words[i][0] - 'a'].push({i, 0});
        }
        for(char ch : s)
        {
            int sz = q[ch-'a'].size();
            while(sz > 0)
            {
                auto [idx, pos] = q[ch-'a'].front();
                
                q[ch-'a'].pop();
                if(pos == words[idx].size()-1) result++;
                else
                {
                    pos++;
                    q[words[idx][pos]-'a'].push({idx, pos});
                }
                sz--;
            }

        }
        
        return result;
    }
};
