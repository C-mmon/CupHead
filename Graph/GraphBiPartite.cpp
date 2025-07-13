class Solution {
public:
    // color 1 means on the right subset,
    //  color 0 means on the left subset
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited,
             int color) {
        if (visited[node] != -1) {
            return visited[node] == color;
        }
        visited[node] = color;
        for (auto i : graph[node]) {
            if (!dfs(i, graph, visited, !color)) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0;i <graph.size(); i++)
        {
            //if there exist multiple component does not matter, 
            if(visited[i] == -1 && !dfs(i, graph, visited, 1))
            {
                return false;
            }
        }
        return true;
    }
};
