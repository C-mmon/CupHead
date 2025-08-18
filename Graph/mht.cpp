class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
                if (n <= 2) {
            vector<int> ans;
            for (int i = 0; i < n; i++) ans.push_back(i);
            return ans;
        }
        unordered_map<int, vector<int>> store;
        vector<int> indegree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            store[u].push_back(v);
            store[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        int countNode = n;
        // we have to make a observation can a node with x
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        
        while (!q.empty()) {
            int qSize = q.size();
            countNode -= qSize;
  
            for (int i = 0; i < qSize; i++) {
                int node = q.front();
                q.pop();
                for (auto v : store[node]) {
                    indegree[v]--;
                    if (indegree[v] == 1) {
                        q.push(v);
                    }
                }
            }
            if(countNode <=2)
            {
                while(!q.empty())
                {
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }

        return ans;
    }
};
