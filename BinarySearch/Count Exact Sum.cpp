int solve(vector<int>& nums, int k) {
    const int MOD = 1e9 + 7;
    int n = nums.size();

    vector<int64_t> dp(k + 1);
    dp[0] = 1;

    for (int& num: nums) {
        for (int i = k; i >= num; i--) {
            dp[i] += dp[i - num] % MOD;
        }
    }

    return dp[k] % MOD;
}