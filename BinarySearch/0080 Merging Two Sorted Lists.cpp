vector<int> solve(vector<int>& a, vector<int>& b) {
    map<int, int> cnt;
    for (int i = 0; i < (int)a.size(); i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i < (int)b.size(); i++) {
        cnt[b[i]]++;
    }

    vector<int> ans;
    for (auto& x: cnt) {
        for (int i = 0; i < x.second; i++) {
            ans.push_back(x.first);
        }
    }
    return ans;
}