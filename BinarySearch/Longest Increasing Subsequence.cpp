// O(n^2) Solution
int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1); // Let dp[i] = LIS from arr[0 ... i]

    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans;
}

// O(n log n) Solution
// Note: LIS is increasing. We can replace a larger value in dp with smaller value and still get the same length
int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        if (dp.empty()) dp.push_back(nums[i]);

        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);

		// Replace the first value in dp that is greater than curr number with a smaller number
        if (it == dp.end()) {
            dp.push_back(nums[i]);
        } else {
            int idx= it - dp.begin();
            dp[idx] = nums[i];
        }
    }

    return dp.size();
}
