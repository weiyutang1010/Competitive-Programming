int solve(string a, string b) {
    int n = a.size(), m = b.size();

    // Let dp[i][j] be the longest common substring between a[0...i] and b[0...j]
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Find the longest common subsequence
    int lcs = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            lcs = max(lcs, dp[i][j]);
        }
    }

    // We want reduce characters so each string has length of lcs
    return n - lcs + m - lcs;
}