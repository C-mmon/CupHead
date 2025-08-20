#include <bits/stdc++.h>
using namespace std;

int termLevel(const string &query, const string &term) {
    int n = query.size();
    int depth = 0;
    int maxLevel = -1;

    for (int i = 0; i < n; ) {
        if (query[i] == '(') {
            // skip redundant (( ))
            if (i + 1 < n && query[i + 1] == '(') {
                // collapse redundant paren
            } else {
                depth++;
            }
            i++;
        } else if (query[i] == ')') {
            // collapse redundant )) is handled naturally
            if (depth > 0) depth--;
            i++;
        } else if (isalpha(query[i])) {
            // extract full term
            string token;
            while (i < n && isalpha(query[i])) {
                token.push_back(query[i]);
                i++;
            }
            if (token == term) {
                maxLevel = max(maxLevel, depth);
            }
        } else {
            i++;
        }
    }
    return maxLevel;
}

int main() {
    vector<pair<string,string>> tests = {
        {"A AND (B OR C)", "B"},
        {"A AND (B OR C)", "A"},
        {"A AND (B OR C)", "D"},
        {"B AND ((A AND B))", "B"},
        {"A AND B OR C", "B"},
        {"((A))", "A"}
    };

    for (auto &t : tests) {
        cout << "query = " << t.first << ", term = " << t.second 
             << " => " << termLevel(t.first, t.second) << "\n";
    }
    return 0;
}
