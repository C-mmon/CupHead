class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list (faster than map)
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& edge : times) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }

        // Min-heap of {accumulatedTime, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        // Use a distance vector for both visited status & shortest time
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currTime, u] = pq.top(); pq.pop();

            // Skip if we already have a better time for this node
            if (currTime > dist[u]) continue;

            for (auto& [v, wt] : graph[u]) {
                int newTime = currTime + wt;
                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    pq.emplace(newTime, v);
                }
            }
        }

        // Get max time to reach any node
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
