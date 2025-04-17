class Solution {
public:
    vector<vector<int>> adj;
    vector<int> indeg;
    vector<bool> visited;
    void build_adj(vector<vector<int>>& prerequisites) {
        for (vector<int>& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
               adj.resize(numCourses);
        indeg.resize(numCourses);
        visited.resize(numCourses, 0);
        
        build_adj(prerequisites);

        // Perform topological sort using BFS (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) 
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            count++;
            for (int j : adj[i]) {
                if (--indeg[j] == 0) 
                    q.push(j);
            }
        }

        return count == numCourses; 
    }
};