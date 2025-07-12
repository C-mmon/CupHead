class Solution {
public:
    vector<int> visited;
    unordered_map<int, vector<int>> graph;
    void dfs(int node) {
        visited[node] = true;
        for (int nextNode : graph[node]) {
            if (!visited[nextNode]) {
                dfs(nextNode);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) {
            return -1;
        }
        visited.resize(n, false);
        for (auto i : connections) {
            int u = i[0];
            int v = i[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        int component = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                component++;
                dfs(i);
            }
        }

        return component - 1;
    }
};
