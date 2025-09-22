#include <iostream>
#include <vector>


using namespace std;

// Function to check if moving from `current` to `next` is valid
bool isValidMove(vector<bool>& visited, int current, int next, vector<vector<int>>& skip) {
    // If `next` is already visited, it is not valid
    if (visited[next]) return false;

    // If there's no skip condition or the skip number is already visited, the move is valid
    if (skip[current][next] == 0 || visited[skip[current][next]]) return true;

    return false;
}

// Depth-First Search to count all patterns
int dfs(vector<bool>& visited, vector<vector<int>>& skip, int current, int remaining) {
    if (remaining == 0) return 1;

    visited[current] = true;
    int totalPatterns = 0;

    // Try all possible next moves
    for (int next = 1; next <= 9; next++) {
        if (isValidMove(visited, current, next, skip)) {
            totalPatterns += dfs(visited, skip, next, remaining - 1);
        }
    }

    visited[current] = false;
    return totalPatterns;
}

// Function to calculate the total number of patterns for a given range of lengths
int androidPatternCount(int minLength, int maxLength) {
    // Skip matrix to handle line numbers (skipped numbers)
    vector<vector<int>> skip(10, vector<int>(10, 0));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[1][9] = skip[9][1] = 5;
    skip[2][8] = skip[8][2] = 5;
    skip[3][7] = skip[7][3] = 5;
    skip[3][9] = skip[9][3] = 6;
    skip[4][6] = skip[6][4] = 5;
    skip[7][9] = skip[9][7] = 8;

    vector<bool> visited(10, false);
    int totalPatterns = 0;

    // Count patterns for each length in the range
    for (int length = minLength; length <= maxLength; length++) {
        // 1, 3, 7, 9 are symmetric
        totalPatterns += dfs(visited, skip, 1, length - 1) * 4;
        // 2, 4, 6, 8 are symmetric
        totalPatterns += dfs(visited, skip, 2, length - 1) * 4;
        // 5 is in the center
        totalPatterns += dfs(visited, skip, 5, length - 1);
    }

    return totalPatterns;
}

int main() {
    int minLength = 1;
    int maxLength = 9;

    cout << "Total patterns: " << androidPatternCount(minLength, maxLength) << endl;

    return 0;
}
