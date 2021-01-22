vector<int> solve(vector<vector<int>>& lists) {
    int count = 0;
    map<int, int> m;
    for (int i = 0; i < (int)lists.size(); i++) {
        for (int j = 0; j < (int)lists[i].size(); j++) {
            m[lists[i][j]]++;
            count++;
        }
    }

    vector<int> ans(count);
    int i = 0;
    for (auto& x: m) {
        for (int j = 0; j < x.second; j++) {
            ans[i] = x.first;
            i++;
        }
    }
    return ans;
}