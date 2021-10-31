vector<string> solve(string s, int k) {
    int n = s.size();
    vector<string> v(k);

    for (int i = 0; i < n; i++) {
        v[i % k].push_back(s[i]); // i % k = {0, 1, 2, ..., k, 0, 1, 2}
    }

    return v;
}
