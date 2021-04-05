struct value {
    string s;
    int n;
};

string solve(string s) {
    int sz = s.size(); // size of string s
    string result = "";
    
    stack<value> st; // Keep track of parenthesis - 1 is ( and 0 is )
    int num_repeat = 0;

    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            // Open parenthesis
            struct value val = {"", num_repeat};
            st.push(val);
            num_repeat = 0;
        } else if (s[i] == ')') {
            // Closing parenthesis
            struct value val = st.top();
            st.pop();

            if (!st.empty()) {
                // val is not nested
                for (int i = 0; i < val.n; i++) {
                    st.top().s += val.s;
                }
            } else {
                // Check if val is nested
                for (int i = 0; i < val.n; i++) {
                    result += val.s;
                }
            }            
        } else {
            if (s[i] >= '0' && s[i] <= '9') {
                // digit for n
                num_repeat = (num_repeat * 10) + (s[i] - '0'); 
            } else {
                // Character
                st.top().s += s[i];
            }
        }
    }

    return result;
}