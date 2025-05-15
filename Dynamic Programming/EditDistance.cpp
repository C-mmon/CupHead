class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // Create a DP table with dimensions (n+1) x (m+1)
        vector<vector<int>> store(n+1, vector<int>(m+1, 0));

        // Initialize the base cases
        for (int i = 0; i <= n; i++) 
            store[i][0] = i; // Cost of deleting all characters of word1
        for (int j = 0; j <= m; j++) 
            store[0][j] = j; // Cost of inserting all characters of word2

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // Characters match, no additional cost
                    store[i][j] = store[i-1][j-1];
                } else {
                    // Take the minimum of insert, delete, or replace
                    store[i][j] = 1 + min({store[i-1][j], store[i][j-1], store[i-1][j-1]});
                }
            }
        }

        // The answer is in the bottom-right cell
        return store[n][m];
    }
};
