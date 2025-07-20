class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
               unordered_set<string> avail(supplies.begin(), supplies.end());

        unordered_map<string, vector<string>> rev;   // ingredient ➜ recipes
        unordered_map<string, int>            need;  // recipe ➜ #missing
        queue<string> q;                            // Kahn queue
        vector<string> ans;

        /* ------------------------------------------------------------
           single pass to
               • build reverse graph
               • compute “missing” counters
               • immediately enqueue recipes that are already doable
        ------------------------------------------------------------ */
        for (int i = 0; i < recipes.size(); ++i) {
            const string &r = recipes[i];
            int missing = 0;

            for (const string &ing : ingredients[i]) {
                if (!avail.count(ing)) {                 // not available yet
                    ++missing;
                    rev[ing].push_back(r);               // ing ➜ r
                }
            }

            if (missing == 0) {                          // cookable now
                q.push(r);
                avail.insert(r);
                ans.push_back(r);
            } else {
                need[r] = missing;                       // remember count
            }
        }

        /* ------------------------------------------------------------
           Kahn-style BFS
        ------------------------------------------------------------ */
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (!rev.count(cur)) continue;               // nothing waited on it

            for (const string &recipe : rev[cur]) {
                if (--need[recipe] == 0) {               // all deps ready
                    q.push(recipe);
                    avail.insert(recipe);
                    ans.push_back(recipe);
                }
            }
        }
        return ans;
    }
};
