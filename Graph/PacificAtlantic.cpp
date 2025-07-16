class Solution {
public:
    vector<int> dir{0, 1, 0, -1, 0}; // For 4-directional movement

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];

                // Check bounds and whether we've already visited the neighbor
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] &&
                    heights[nx][ny] >= heights[x][y]) {

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // Fill boundary for Pacific and Atlantic
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            pacificQueue.push({i, 0});
            atlantic[i][m - 1] = true;
            atlanticQueue.push({i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            pacificQueue.push({0, j});
            atlantic[n - 1][j] = true;
            atlanticQueue.push({n - 1, j});
        }

        // Run BFS from both oceans
        bfs(pacificQueue, pacific, heights);
        bfs(atlanticQueue, atlantic, heights);

        // Collect cells reachable by both oceans
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        sort(ans.begin(), ans.end()); // Optional: sort result
        return ans;
    }
};
