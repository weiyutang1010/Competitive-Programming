int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    sort(nums.begin(), nums.end());

    int ans = 0;
    vector<int> dp(n);
    // Do longest increasing subsequence but with divisible
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans + 1;
}
