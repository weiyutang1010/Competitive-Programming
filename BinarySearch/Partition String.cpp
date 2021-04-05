vector<int> solve(string s) {
    if (s == "") return vector<int> ();

    int n = s.size();
    vector<int> ans;
    unordered_map<char, pair<int, int>> m;
    // Create interval for each character
    for (int i = 0; i < n; i++) {
        if (m[s[i]].first) {
            m[s[i]] = {m[s[i]].first, i+1};
        } else {
            m[s[i]] = {i+1, i+1};
        }
    }
    
    // Merge interval that intersects
    int curr_l = 0, curr_r = m[s[0]].second - 1;
    for (int i = 0; i < n; i++) {
        int rt = m[s[i]].second - 1;
        curr_r = max(curr_r,rt);
        if (i >= curr_r) {
            // printf("i: %d lt: %d rt: %d\n", i, curr_l, curr_r);
            ans.push_back(curr_r - curr_l + 1);
            curr_r = i + 1;
            curr_l = i + 1;
        }
    }

    if (ans.size() == 0) {
        if (s.size() > 0) {
            ans.push_back(s.size());
        }
    }

    return ans;
}