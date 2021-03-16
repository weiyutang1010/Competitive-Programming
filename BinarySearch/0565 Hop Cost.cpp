int solve(vector<int>& nums0, vector<int>& nums1, int dist, int cost) {
    int n = nums0.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int> (2, INT_MAX));
    
    dp[0][0] = nums0[0], dp[0][1] = nums1[0];
    for (int i = 1; i < n; i++) {
        for (int j = max(0, i - dist); j < i; j++) {
            dp[i][0] = min(dp[i][0], min(dp[j][0], dp[j][1] + cost) + nums0[i]);
            dp[i][1] = min(dp[i][1], min(dp[j][1], dp[j][0] + cost) + nums1[i]);
        }
    }

    return min(dp[n-1][0], dp[n-1][1]);
}