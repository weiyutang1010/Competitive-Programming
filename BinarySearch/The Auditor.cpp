int solve(string s) {
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (s[i] - 'A' + 1) * pow(26, n - (i + 1));
    }

    return ans;
}
