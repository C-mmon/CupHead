#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

bool isValidChar(char c) {
    return islower(c) || c == '*';
}

void bfsTraverse(const vector<string>& path) {
    int rows = path.size();
    int cols = path[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<vector<int>> dir {{0,1}, {1,0}, {0,-1}, {-1,0}};

    queue<pair<int,int>> q;
    if (isValidChar(path[0][0])) {
        q.push({0, 0});
        visited[0][0] = 1;
    }

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            char currentChar = path[x][y];
            cout << "Visiting (" << x << "," << y << ") = " << currentChar << endl;

            for (int d = 0; d < 4; ++d) {
                int newX = x + dir[d][0];
                int newY = y + dir[d][1];

                if (newX < 0 || newY < 0 || newX >= rows || newY >= cols)
                    continue;

                if (visited[newX][newY])
                    continue;

                if (!isValidChar(path[newX][newY]))
                    continue;

                q.push({newX, newY});
                visited[newX][newY] = 1;
            }
        }
    }
}
