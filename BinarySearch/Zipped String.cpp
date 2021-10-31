bool solve(string a, string b, string c) {
    int n = a.size(), m = b.size(), k = c.size();
    if (k != n + m) return false;

    vector<vector<bool>> dp(n+1, vector<bool> (m+1));
    dp[0][0] = 1;

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            if (i > 0 && dp[i-1][j] && a[i-1] == c[i+j-1]) {
                dp[i][j] = 1;
            }

            if (j > 0 && dp[i][j-1] && b[j-1] == c[i+j-1]) {
                dp[i][j] = 1;
            }
        }
    }

    return dp[n][m];
}
