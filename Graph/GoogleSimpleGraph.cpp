#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for(int i = 0; i < N; i++)
        cin >> grid[i];

    pair<int,int> S, T;
    // locate S and T
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 'S') S = {i, j};
            if(grid[i][j] == 'T') T = {i, j};
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int,int>> q;
    q.push(S);
    visited[S.first][S.second] = true;

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    bool found = false;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(x == T.first && y == T.second) {
            found = true;
            break;
        }
        for(auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N
               && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << (found ? "YES" : "NO") << "\n";
    return 0;
}
