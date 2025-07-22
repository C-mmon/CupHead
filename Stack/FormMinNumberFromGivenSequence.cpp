#include <bits/stdc++.h>
using namespace std;

string getMinNumberForPattern(string pattern) {
    string result = "";
    stack<int> st;
    int num = 1;

    for (int i = 0; i <= pattern.length(); i++) {
        st.push(num++);

        // if current is 'I' or we are at the end
        if (i == pattern.length() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }

    return result;
}
