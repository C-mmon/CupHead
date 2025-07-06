#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main() {
    string a = "abcxyz";
    string b = "xyzuvw";
    reverse(b.begin(), b.end());

    string newString = a + "#" + b;

    vector<int> lps = computeLPS(newString);

    // Print LPS array
    for (int x : lps) {
        cout << x << " ";
    }
    cout << endl;
}
