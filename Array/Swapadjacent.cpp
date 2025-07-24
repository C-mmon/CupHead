class Solution {
public:
    bool canTransform(string start, string result) {

        pair<int, int> ss;
        ss.first = 0;
        ss.second = 0;
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < result.size(); i++) {
            if (start[i] == 'L') {
                ss.first++;
                s1 += 'L';
            } else if (start[i] == 'R') {
                ss.second++;
                s1 += 'R';
            }
            if (result[i] == 'L') {
                ss.first--;
                s2 += 'L';
            } else if (result[i] == 'R') {
                ss.second--;
                s2 += 'R';
            }
        }
        if (ss.first != 0 || ss.second != 0 || s1 != s2) {
            return false;
        }

        int i = 0, j = 0;
        string p = "", q = "";
        while (i < start.size() && j < result.size()) {
            while (i < start.size() && start[i] == 'X')
                i++;
            while (j < result.size() && result[j] == 'X')
                j++;
            // End check
            if (i == start.size() || j == result.size())
                break;

            // If characters mismatch
            if (start[i] != result[j])
                return false;

            // Movement rules
            if (start[i] == 'L' && j > i)
                return false; // L can't move right
            if (start[i] == 'R' && j < i)
                return false; // R can't move left

            i++;
            j++;
        }

        // Any remaining non-X characters should be skipped
        while (i < start.size() && start[i] == 'X') i++;
        while (j < result.size() && result[j] == 'X') j++;

        return i == start.size() && j == result.size();
    }
};
