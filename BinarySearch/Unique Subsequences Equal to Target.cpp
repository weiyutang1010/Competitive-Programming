int solve(string s, string t) {
    int64_t n = s.size();
    int64_t m = t.size();
    if (n == 0 || m == 0) return 0;
    int64_t MOD = 1e9 + 7;

    // Let dp[i][j] = unique subsequence for first i idx of t string and first j idx of s string
    vector<vector<int64_t>> dp(m+1, vector<int64_t> (n+1));

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            if (i == 1) {
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1]);
            } else {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % MOD;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[m][n] % MOD;
}
