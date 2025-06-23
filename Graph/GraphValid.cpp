class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;  // Must have exactly n-1 edges

        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
      //we are passing a sentinel value to ensure we dont visit back the same node again
      //since we are beginning from node 0, 0 has no previous, 
      
        if (!dfs(0, -1, graph, visited)) return false;

        // Check if all nodes were visited (i.e., connected)
        for (bool v : visited)
            if (!v) return false;

        return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
      //we dont go back to the visited 
        if (visited[node]) return false;
        visited[node] = true;

        for (int neighbor : graph[node]) {
          //we dont want to go back to our parent
            if (neighbor == parent) continue; // Don't go back to parent
            if (!dfs(neighbor, node, graph, visited)) return false;
        }
        return true;
    }
};
