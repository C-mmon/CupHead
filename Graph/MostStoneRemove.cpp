class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    void dfs(pair<int, int> stone,
             unordered_set<pair<int, int>, pair_hash>& visited,
             unordered_map<int, vector<pair<int, int>>>& rows,
             unordered_map<int, vector<pair<int, int>>>& cols) {

        visited.insert(stone);

        // Explore same row
        for (auto& nei : rows[stone.first]) {
            if (visited.find(nei) == visited.end()) {
                dfs(nei, visited, rows, cols);
            }
        }

        // Explore same column
        for (auto& nei : cols[stone.second]) {
            if (visited.find(nei) == visited.end()) {
                dfs(nei, visited, rows, cols);
            }
        }
    }



    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<pair<int, int>>> rows, cols;
        unordered_set<pair<int, int>, pair_hash> visited;

        // Build row and column maps
        for (auto& stone : stones) {
            pair<int, int> p = {stone[0], stone[1]};
            rows[stone[0]].push_back(p);
            cols[stone[1]].push_back(p);
        }

        int numComponents = 0;
        for (auto& stone : stones) {
            pair<int, int> p = {stone[0], stone[1]};
            if (visited.find(p) == visited.end()) {
                dfs(p, visited, rows, cols);
                numComponents++;
            }
        }

        return stones.size() - numComponents;
    }
};
