class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
       int n = mat.size();
        int candidate = 0;

        // Step 1: Find a potential candidate
        for (int i = 1; i < n; ++i) {
            if (mat[candidate][i]) {
                candidate = i;
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; ++i) {
            if (i != candidate) {
                // If candidate knows i or i doesn't know candidate -> not a celebrity
                if (mat[candidate][i] || !mat[i][candidate]) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
