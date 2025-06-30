#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string>& res, string& expr, const string& digits,
               int target, int idx, long long eval, long long last) {
    if (idx == digits.size()) {
        if (eval == target) {
            res.push_back(expr);
        }
        return;
    }

    int exprLen = expr.size(); // save size to undo later

    for (int i = idx; i < digits.size(); ++i) {
        if (i != idx && digits[idx] == '0') break;

        string part = digits.substr(idx, i - idx + 1);
        long long num = stoll(part);

        if (idx == 0) {
            expr += part;
            backtrack(res, expr, digits, target, i + 1, num, num);
            expr.resize(exprLen); // undo
        } else {
            // Try '+'
            expr += '+' + part;
            backtrack(res, expr, digits, target, i + 1, eval + num, num);
            expr.resize(exprLen); // undo

            // Try '-'
            expr += '-' + part;
            backtrack(res, expr, digits, target, i + 1, eval - num, -num);
            expr.resize(exprLen); // undo

            // Try '*'
            expr += '*' + part;
            backtrack(res, expr, digits, target, i + 1,
                      eval - last + last * num, last * num);
            expr.resize(exprLen); // undo
        }
    }
}

vector<string> addOperators(string digits, int target) {
    vector<string> res;
    string expr;
    backtrack(res, expr, digits, target, 0, 0, 0);
    return res;
}


Final Summary Table
Topic	Summary
Pass-by-value	Copy → no side-effects
Pass-by-reference	Alias → changes persist
pop_back() usage	Required when mutating shared state (reference), not with copied state
break on leading zero	All longer substrings are invalid (like "01")
No direct negatives	Input is pure digits → negatives only arise via operators
eval - last + last * num	Rolls back previous op and applies correct * precedence
