#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to check if a string has valid parentheses
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }

    // DFS backtracking to generate all valid results
    void dfs(const string& s, int start, int left, int right,
             unordered_set<string>& result, unordered_set<string>& visited) {
        if (left == 0 && right == 0) {
            if (isValid(s)) result.insert(s);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string curr = s.substr(0, i) + s.substr(i + 1);

            if (visited.count(curr)) continue;
            visited.insert(curr);

            if (s[i] == ')' && right > 0) {
                dfs(curr, i, left, right - 1, result, visited);
            } else if (s[i] == '(' && left > 0) {
                dfs(curr, i, left - 1, right, result, visited);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        // First pass to count misplaced '(' and ')'
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left == 0) right++;
                else left--;
            }
        }

        unordered_set<string> result;
        unordered_set<string> visited;
        visited.insert(s);
        dfs(s, 0, left, right, result, visited);

        return vector<string>(result.begin(), result.end());
    }
};
