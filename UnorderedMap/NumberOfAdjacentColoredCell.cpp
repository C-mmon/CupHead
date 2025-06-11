class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
            vector<int> color(n, 0); // initially all unpainted
        int sameAdj = 0;
        vector<int> res;

        for (auto& q : queries) {
            int i = q[0], c = q[1];

            // Remove existing adjacent match before recoloring
            if (color[i] != 0) {
                if (i > 0 && color[i - 1] == color[i]) sameAdj--;
                if (i < n - 1 && color[i + 1] == color[i]) sameAdj--;
            }

            color[i] = c; // paint the index

            // Add new adjacent match
            if (i > 0 && color[i - 1] == color[i]) sameAdj++;
            if (i < n - 1 && color[i + 1] == color[i]) sameAdj++;

            res.push_back(sameAdj);
        }

        return res;
    }
};
