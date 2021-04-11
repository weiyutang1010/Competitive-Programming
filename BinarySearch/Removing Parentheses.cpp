int solve(string s) {
    stack<int> st;

    for (char& c: s) {
        if (c == '(') st.push(c);
        else {
            // Pop all valid bracket
            if (!st.empty() && c == ')' && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    
    return st.size();
}