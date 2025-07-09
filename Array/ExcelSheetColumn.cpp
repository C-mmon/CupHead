class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res =0;
        for(char ch: columnTitle)
        {
            int d = (ch-'A'+1);
            res = res*26+d;
        }

        return res;
    }
};
