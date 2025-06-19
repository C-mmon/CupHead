    int rows = city.size();
    int cols = city[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;

    // Step 1: Push all DashMarts into the queue
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (city[r][c] == 'D') {
                dist[r][c] = 0;
                q.emplace(r, c);
            }
        }
    }

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // Step 2: Multi-source BFS
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                city[nr][nc] == ' ' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }

    // Step 3: Answer each query
    vector<int> result;
    for (const auto& loc : locations) {
        int r = loc[0];
        int c = loc[1];

        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            result.push_back(dist[r][c]);
        } else {
            result.push_back(-1);
        }
    }

    return result;
