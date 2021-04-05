vector<int> solve(vector<vector<int>>& relations) {
    int n = relations.size();
    map<vector<int>, int> m;
    set<int> ans;
    for (int i = 0; i < n; i++) {
        vector<int> p = {relations[i][1],relations[i][0]};
        if (m[p]) {
            ans.insert(p[0]);
            ans.insert(p[1]);
        } else {
            m[relations[i]] = 1;
        }
    }

    return vector<int> (ans.begin(), ans.end());
}