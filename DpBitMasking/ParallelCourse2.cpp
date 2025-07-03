class Solution {
public:
    int n, k;
    vector<int> prereq;
    unordered_map<int, int> memo;

    // DFS to compute min semesters from a given course completion state
    int dfs(int mask) {
        // All courses completed
        if (mask == (1 << n) - 1) return 0;
        if (memo.count(mask)) return memo[mask];

        vector<int> available;
        // Find courses whose prerequisites are met and not yet taken
        for (int i = 0; i < n; ++i) {
            if (((mask >> i) & 1) == 0 && (prereq[i] & mask) == prereq[i]) {
                available.push_back(i);
            }
        }

        int res = INT_MAX;

        if (available.size() <= k) {
            // Can take all available courses
            int nextMask = mask;
            for (int course : available) {
                nextMask |= (1 << course);
            }
            res = 1 + dfs(nextMask);
        } else {
            // Need to generate all combinations of k courses
            vector<int> temp;
            vector<int> subsets;
            generateCombinations(available, k, 0, temp, subsets);

            for (int subsetMask : subsets) {
                res = min(res, 1 + dfs(mask | subsetMask));
            }
        }

        return memo[mask] = res;
    }

    // Helper to generate all combinations of k elements from available
    void generateCombinations(vector<int>& available, int k, int start,
                              vector<int>& temp, vector<int>& result) {
        if (temp.size() == k) {
            int bitmask = 0;
            for (int course : temp) {
                bitmask |= (1 << course);
            }
            result.push_back(bitmask);
            return;
        }

        for (int i = start; i < available.size(); ++i) {
            temp.push_back(available[i]);
            generateCombinations(available, k, i + 1, temp, result);
            temp.pop_back(); // backtrack
        }
    }

    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        n = N;
        k = K;
        prereq.assign(n, 0);
        memo.clear();

        // Build bitmask representation of prerequisites
        for (auto& r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;
            prereq[v] |= (1 << u);
        }

        return dfs(0);
    }
};
