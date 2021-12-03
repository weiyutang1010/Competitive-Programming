int solve(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 1) return nums[0];

    vector<int> dp(n);
    deque<int> window;

    dp[0] = nums[0];
    window.push_back(0);

    // Check method 3:
    // https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
    for (int i = 1; i < n; i++) {
        // pop everything at the front that is outside window
        while (!window.empty() && window.front() < i - k) {
            window.pop_front();
        }

        dp[i] = dp[window.front()] + nums[i];
        
        // pop everything at the back that is greater/smaller than current element
        while (!window.empty() && dp[window.back()] >= dp[i]) {
            window.pop_back();
        }

        window.push_back(i);
    }

    return dp[n-1];
}
