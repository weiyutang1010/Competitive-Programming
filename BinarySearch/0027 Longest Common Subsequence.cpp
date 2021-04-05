int solve(string a, string b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return 0;
    
    // Let dp[i][j] be the longest common substring between a[0...i] and b[0...j]
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}