Yeah, my initial thought process regarding add edges to make degree.
I mean the least I could come up under few minutes was to count the indegree, check odd indegree, 
There can be multiple odd degree, each odd degree edges might already have an existing connection with another odd degree, 
so we will ignore those while traversing, but it gets more tricky,
Now, with the constraint, we can add atmost two edges,
hence, we need to find all the possible combination, that is fixing 2 nodes or fixing 4 nodes.
Now, the problem with 2 node is that, if there does not exist between them you can connect them directly, otherwise, you need to look for third edge that will connect both these node, such that both node is not connected to this node and further, this node is not the odd node itself.

Now, for the 4 node logic, is the most tricky one, and its really hard to come during the interview itself.
This must be clear that you need 4 node with 2 pair to connect.

check if you can add a edge between a to b and c to d.
a to b and the c to d,
a to d and then c to b
a to c and then b to d

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
         vector<int> degree(n + 1, 0);
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            adj[u][v] = true;
            adj[v][u] = true;
        }

        vector<int> oddNodes;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] % 2 == 1)
                oddNodes.push_back(i);
        }

        int oddCount = oddNodes.size();

        if (oddCount == 0)
            return true;

        if (oddCount == 2) {
            int a = oddNodes[0], b = oddNodes[1];
            // If edge doesn't exist between them, we can connect directly
            if (!adj[a][b]) return true;

            // Try finding a third node c that can be connected to both a and b
            for (int c = 1; c <= n; ++c) {
                if (c != a && c != b && !adj[a][c] && !adj[b][c]) {
                    return true;
                }
            }

            return false;
        }

        if (oddCount == 4) {
            // Try all 3 pair combinations (3 matchings of 4 nodes)
            int a = oddNodes[0], b = oddNodes[1], c = oddNodes[2], d = oddNodes[3];

            return (
                (!adj[a][b] && !adj[c][d]) ||
                (!adj[a][c] && !adj[b][d]) ||
                (!adj[a][d] && !adj[b][c])
            );
        }

        // If odd count is 1, 3, or > 4 — impossible with just 2 edges
        return false;
    }
};
