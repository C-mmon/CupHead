class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
     int orangesRotting(vector<vector<int>> &
                                                          grid) {
        queue<pair<int, int>> store;
        int time = 0;
        int countOranges = 0;
        int rottenOrangeCount = 0;
        // first we need to push all the rotten oranges in the queue
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    store.push({i, j});
                }
                if (grid[i][j] != 0) {
                    countOranges++;
                }
            }
        }
        while (!store.empty()) {
            rottenOrangeCount += store.size();
            int bfsQueueSize = store.size();

            while (bfsQueueSize--) {
                pair<int, int> temp = store.front();
                store.pop();
                int xCord = temp.first, yCord= temp.second;
                for (int i = 0; i < 4; i++) {
                    int newXCord = xCord + dir[i];
                    int newYCord = yCord + dir[i+1];
                    if (newXCord < grid.size() && newXCord >= 0 &&
                        newYCord >= 0 && newYCord < grid[0].size() &&
                        grid[newXCord][newYCord] == 1) {
                        store.push({newXCord, newYCord});
                        grid[newXCord][newYCord] = 2;
                    }
                }
            }
            if (!store.empty()) {
                time++;
            }
        }
        if (countOranges == rottenOrangeCount) {
            return time;
        }
        return -1;
    }
};
