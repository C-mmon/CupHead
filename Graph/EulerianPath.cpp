// C++ program to check whether a graph is
// Eulerian Path, Eulerian Circuit, or neither
#include <bits/stdc++.h>
using namespace std;

// DFS to check connectivity, excluding zero-degree vertices
void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Function to check Eulerian Path or Circuit
int isEulerCircuit(int v, vector<int> adj[]) {
    vector<bool> visited(v, false);

    // Find first vertex with non-zero degree
    int start = -1;
    for (int i = 0; i < v; i++) {
        if (adj[i].size() > 0) {
            start = i;
            break;
        }
    }

    // No edges: graph is trivially Eulerian
    if (start == -1) {
        return 2;
    }

    // DFS from the first non-zero degree vertex
    dfs(start, adj, visited);

    // Check if all non-zero degree vertices are connected
    for (int i = 0; i < v; i++) {
        if (adj[i].size() > 0 && !visited[i]) {
            return 0; // Not connected
        }
    }

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < v; i++) {
        if (adj[i].size() % 2 != 0) {
            odd++;
        }
    }

    // Apply Eulerian rules
    if (odd == 0) {
        return 2; 
    } else if (odd == 2) {
        return 1; 
    } else {
        return 0; 
    }
}

// Driver code
int main() {
    
    int v = 5;
    vector<int> adj[5] = {{1, 2, 3}, {0, 2}, 
                          {1, 0}, {0, 4}, {3}};

    cout << isEulerCircuit(v, adj);

    return 0;
}
