bool solve(int n, vector<vector<int>>& friends) {
    int sz = friends.size();
    vector<int> v(n);
    for (int i = 0; i < sz; i++) {
        v[friends[i][0]] = 1;
        v[friends[i][1]] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == 0) return false;
    }
    return true;
}