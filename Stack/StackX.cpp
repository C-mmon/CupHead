bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if (ch == 'X') {
            // Try to treat it as an opening bracket
            st.push('X');
        }
        else { // Closing bracket
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && (top == '(' || top == 'X')) ||
                (ch == ']' && (top == '[' || top == 'X')) ||
                (ch == '}' && (top == '{' || top == 'X')))
                st.pop();
            else
                return false;
        }
    }

    // After parsing all characters, make sure all open brackets are matched
    // Only unmatched real brackets are a problem
    while (!st.empty()) {
        if (st.top() == 'X') {
            st.pop();
        } else {
            return false;
        }
    }

    return true;
}
