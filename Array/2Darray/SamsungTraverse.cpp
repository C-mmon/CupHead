#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a = {
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    int m = a.size();
    int n = a[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; ++i) {
        bool hasOne = false;
        for (int x : a[i]) if (x == 1) hasOne = true;

        if (!hasOne) {
            cout << -1 << endl;  // impossible, as no 1 to reach
            return 0;
        }

        // Forward pass
        int last_one = -1;
        for (int j = 0; j < 2 * n; ++j) {
            int idx = j % n;
            if (a[i][idx] == 1) last_one = j;
            if (last_one != -1) {
                dist[i][idx] = min(dist[i][idx], j - last_one);
            }
        }

        // Backward pass
        last_one = -1;
        for (int j = 2 * n - 1; j >= 0; --j) {
            int idx = j % n;
            if (a[i][idx] == 1) last_one = j;
            if (last_one != -1) {
                dist[i][idx] = min(dist[i][idx], last_one - j);
            }
        }
    }

    // Now compute column-wise sums
    int ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
        int col_sum = 0;
        for (int i = 0; i < m; ++i) {
            col_sum += dist[i][j];
        }
        ans = min(ans, col_sum);
    }

    cout << ans << endl;
    return 0;
}
