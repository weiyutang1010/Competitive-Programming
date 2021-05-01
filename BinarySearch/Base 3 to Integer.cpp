int solve(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (s[i] - '0') * pow(3, n - i - 1);
    }
    return ans;
}