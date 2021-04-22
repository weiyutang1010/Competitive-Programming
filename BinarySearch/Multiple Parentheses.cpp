int solve(string s) {
    int n = s.size();
    stack<pair<int, int>> st; // {type, idx}
    vector<int> valid(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push({s[i], i});
        } else {
            if (!st.empty() && st.top().first == '(') {
                valid[i] = 1;
                valid[st.top().second] = 1;
                st.pop();
            }
        }
    }

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (valid[i] == 1) curr++;
        else curr = 0;
        ans = max(ans, curr);
    }

    return ans;
}