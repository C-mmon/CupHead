class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        
        int m = s.length(), n = p.length();
        vector<vector<bool>> M(m + 1, vector<bool>(n + 1, false));
        
        // Initialization
        M[0][0] = true;
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*' && M[0][j - 2]) {
                M[0][j] = true;
            }
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char curS = s[i - 1];
                char curP = p[j - 1];
                
                if (curS == curP || curP == '.') {
                    M[i][j] = M[i - 1][j - 1];
                } else if (curP == '*') {
                    char preCurP = p[j - 2];
                    //If:The previous pattern character (preCurP) is not ., and
                    //It does not match the current string character (curS),
                    //Then:
                    //There's no way the * can match the current string character.
                    //So your only option is to ignore the 'preCurP*' (treat it as matching zero occurrences).
                    if (preCurP != '.' && preCurP != curS) {
                        M[i][j] = M[i][j - 2];
                    } else {
                        //“If I match the current s[i - 1] with 'char*', then can the previous part of s match the same pattern?”
                        M[i][j] = M[i][j - 2] ||  M[i - 1][j];
                    }
                }
            }
        }
        
        return M[m][n];
    }
};
