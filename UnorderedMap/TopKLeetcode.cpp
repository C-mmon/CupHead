class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         using pii = pair<int, string>; // {wordCount, username}
auto cmp = [](const pii& a, const pii& b) {
    if (a.first == b.first)
        return a.second < b.second; // reverse lex order for min-heap
    return a.first > b.first; // min-heap: lower frequency comes first
};
        unordered_map <string, int> st;
        priority_queue<pii, vector<pii>, decltype(cmp)> minHeap(cmp);
        for(auto i: words)
        {
            st[i]++;
        }
        vector <string> res;
        for(auto const& i: st)
        {
            minHeap.push({i.second, i.first});
            if(minHeap.size() >  k)
            {
                minHeap.pop();
            }
        }
        while(!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
