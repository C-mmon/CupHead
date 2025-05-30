class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans (searchWord.size());
        auto beginSearch = products.begin();
        string prefix = "";
        for(int i=0; i< searchWord.size(); i++)
        {
            prefix+=searchWord[i];
            beginSearch = lower_bound(beginSearch, products.end(), prefix);
            for(auto it = beginSearch; it != products.end() && ans[i].size() < 3; ++it)
            {
                //check if it substring matchers or 
                if(it->substr(0, prefix.size()) == prefix)
                {
                    ans[i].push_back(*it);
                }
                else
                {
                    break;
                }
            }
            
        }
        return ans;
    }
};
