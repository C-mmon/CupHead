class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                mp[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int qf = q.front();
            q.pop();
            res.push_back(qf);
            for (auto i : mp[qf]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
