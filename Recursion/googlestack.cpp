#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int i = 0;

    string decodeString(const string& s) {
        string result = "";
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++; // skip '['
                string decoded = decodeString(s);
                result += string(decoded.begin(), decoded.end()) * k;
            } else if (s[i] == ']') {
                i++;
                return result;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "3[a]2[bc]";
    cout << sol.decodeString(s) << endl;  // Output: aaabcbc
    return 0;
}