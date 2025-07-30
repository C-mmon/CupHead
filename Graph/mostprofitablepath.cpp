class Solution {
public:
    int dfs(int currNode, int parent, int time, vector<int>& bobTime,
            unordered_map<int, vector<int>>& mp, vector<int>& amount) {

        int gain = 0;
        if (time < bobTime[currNode]) {
            gain = amount[currNode];
        } else if (time == bobTime[currNode]) {
            gain = amount[currNode] / 2;
        }

        //amount can have a negativev value
        int best = INT_MIN;
        for (int neighbor : mp[currNode]) {
            if (neighbor != parent) {
                int childProfit =
                    dfs(neighbor, currNode, time + 1, bobTime, mp, amount);
                best = max(best, childProfit);
            }
        }

        //in the scenario, where the best rturn 0, due to the gain, that is at the last leaf node
        // best will be not initialise and it will return INT_MIN
        
        if (best == INT_MIN) {
            return gain;
        }

        return gain + best;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        unordered_map<int, vector<int>> mp;

        for (auto& e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        int n = amount.size();
        vector<int> bobTime(n, INT_MAX); // by default, Bob never visits

        // backtrack from bob to 0 to set arrival time
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        // BFS to record parent path from root
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (int nei : mp[node]) {
                if (!visited[nei]) {
                    parent[nei] = node;
                    q.push(nei);
                }
            }
        }

        int t = 0;
        int curr = bob;
        while (curr != -1) {
            bobTime[curr] = t++;
            curr = parent[curr];
        }

        return dfs(0, -1, 0, bobTime, mp, amount);
    }
};
