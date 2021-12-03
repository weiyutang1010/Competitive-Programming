int solve(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefix_sum(n+1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
    }

    // Calculate the initial value
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += (i+1) * nums[i];
    }

    // WLOG, Assume j > i. If we move a number from i to j, then the new value is
    // curr + ((j - i) * nums[i]) - (nums[i+1] ... nums[j])
    // (nums[i+1] ... nums[j]) can be calculated in O(1) using prefix sum.

    int ans = curr;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, curr + (nums[i] * (j - i)) - (prefix_sum[j+1] - prefix_sum[i+1]));
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            ans = max(ans, curr - (nums[i] * (i - j)) + (prefix_sum[i] - prefix_sum[j]));
        }
    }

    return ans;
}
