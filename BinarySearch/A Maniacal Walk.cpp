int solve(int length, int n) {
    const int64_t MOD = 1e9 + 7;

    // dp[i] is the number of unique way to reach index i
    int len = min(n + 1, length);
    vector<int64_t> dp(len, 0);
    dp[0] = 1;

    // For each step 0 .. n
    for (int i = 0; i < n; i++) {
        vector<int64_t> new_dp(len, 0);

        // unique way to reach index i at step n is
        // number of ways to reach (i - 1) + (i) + (i + 1)
        for (int j = 0; j < len; j++) {
            if (j != 0 && j != length - 1) {
                new_dp[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % MOD;
            } else if (j == 0) {
                new_dp[j] = (dp[j] + dp[j + 1]) % MOD;
            } else {
                new_dp[j] = (dp[j - 1] + dp[j]) % MOD;
            }
        }
        dp = new_dp;
    }

    // return dp[0] since we will return to index 0
    return dp[0] % MOD;
}