int solve(string a, string b, string c) {
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    int idx1 = 0, idx2 = 0, idx3 = 0;

    // Generalize lcs dp from 2d to 3d
    vector<vector<vector<int>>> dp (n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, 0)));
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= n3; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                } else if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }

    return dp[n1][n2][n3];
}