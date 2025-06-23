//think like this in the dictionary, the dict would have automatically when comparing abcccc and comparing abz, dictionary will compare till c and z after that 
// it will automatically assume samme for abd and acd, dicitionary would order them just by looking at abd and acd.
// Use only the first character mismatch between each adjacent word pair to infer the character order.

// Further, note that we are first pushing the element in the topo and after that we are checking and visiting the neightbour
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u)
            for (int v : adj[u])
                indegree[v]++;

        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];

        // Build graph
        for (int i = 0; i < N - 1; ++i) {
            string &s1 = dict[i], &s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; ++j) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Topological sort
        vector<int> topo = topoSort(K, adj);
        string res;
        for (int u : topo)
            res += (char)(u + 'a');

        return res;
    }
};

int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string order = obj.findOrder(dict, N, K);

    for (char ch : order)
        cout << ch << ' ';
    cout << endl;

    return 0;
}
