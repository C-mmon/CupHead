class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    void dfs(unordered_map<int, vector<int>>& column,
             unordered_map<int, vector<int>>& rows, int row, int col,
             unordered_set<pair<int, int>, pair_hash>& visited) {
        if (visited.count({row, col}))
            return;
        visited.insert({row, col});
        for (auto nextRow : column[col]) {
            dfs(column, rows, nextRow, col, visited);
        }

        for (auto nextCol : rows[row]) {
            dfs(column, rows, row, nextCol, visited);
        }

        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> column;
        unordered_map<int, vector<int>> rows;

        for (int i = 0; i < stones.size(); i++) {
            column[stones[i][1]].push_back(stones[i][0]);
            rows[stones[i][0]].push_back(stones[i][1]);
        }

        unordered_set<pair<int, int>, pair_hash> visited;
        int componentsize = 0;
       for (const auto& s : stones) {
            if (!visited.count({s[0], s[1]})) {
                dfs(column, rows, s[0], s[1], visited);
                ++componentsize;
            }
       }
           

        return stones.size() - componentsize;
    }
};
