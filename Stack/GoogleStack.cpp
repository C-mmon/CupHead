#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

string decodeString(const string& s) {
    stack<pair<string, int>> st;
    string currStr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // Build multi-digit number
        } else if (ch == '[') {
            // Push current context to stack
            st.push({currStr, num});
            currStr = "";
            num = 0;
        } else if (ch == ']') {
            // Pop previous context
            auto [prevStr, repeat] = st.top(); st.pop();
            string expanded;
            for (int i = 0; i < repeat; ++i) {
                expanded += currStr;
            }
            currStr = prevStr + expanded;
        } else {
            // Regular character
            currStr += ch;
        }
    }

    return currStr;
}
