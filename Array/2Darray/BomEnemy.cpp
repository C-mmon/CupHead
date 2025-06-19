class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // Get the number of rows and columns in the grid.
        int rows = grid.size(), cols = grid[0].size();

        // Create a 2D vector to store the number of enemies that can be killed for each cell.
        vector<vector<int>> killCount(rows, vector<int>(cols, 0));

        // Traverse the grid to calculate potential kills horizontally.
        for (int i = 0; i < rows; ++i) {
            int consecutiveEnemies = 0;
            // Left to right sweep
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'W') {
                    consecutiveEnemies = 0;
                } else if (grid[i][j] == 'E') {
                    ++consecutiveEnemies;
                }
                killCount[i][j] += consecutiveEnemies;
            }
            // Reset the counter for the right to left sweep
            consecutiveEnemies = 0;
            // Right to left sweep
            for (int j = cols - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    consecutiveEnemies = 0;
                } else if (grid[i][j] == 'E') {
                    ++consecutiveEnemies;
                }
                killCount[i][j] += consecutiveEnemies;
            }
        }

        // Traverse the grid to calculate potential kills vertically.
        for (int j = 0; j < cols; ++j) {
            int consecutiveEnemies = 0;
            // Top to bottom sweep
            for (int i = 0; i < rows; ++i) {
                if (grid[i][j] == 'W') {
                    consecutiveEnemies = 0;
                } else if (grid[i][j] == 'E') {
                    ++consecutiveEnemies;
                }
                killCount[i][j] += consecutiveEnemies;
            }
            // Reset the counter for the bottom to top sweep
            consecutiveEnemies = 0;
            // Bottom to top sweep
            for (int i = rows - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    consecutiveEnemies = 0;
                } else if (grid[i][j] == 'E') {
                    ++consecutiveEnemies;
                }
                killCount[i][j] += consecutiveEnemies;
            }
        }

        // Find the maximum number of enemies that can be killed by placing a bomb on an empty cell.
        int maxKills = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '0') {
                    maxKills = max(maxKills, killCount[i][j]);
                }
            }
        }
      
        return maxKills;
    }
};
