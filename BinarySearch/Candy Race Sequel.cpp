bool solve(vector<int>& nums) {
    int n = nums.size();
	
	// Let dp[i] = max candies that can be obtained starting at i candy
    // Since we calculate dp from the end, only last 3 values are needed
	vector<int> dp(3); 

    for (int i = n-1; i >= 0; i--) {
        int profit = INT_MIN;
        int candy_sum = 0;

		// Check sum of candy - dp[j - i]
        for (int j = i; j < min(i+3, n); j++) {
            candy_sum += nums[j];
            profit = max(profit, candy_sum - dp[j - i]);
        }

        dp[2] = dp[1];
        dp[1] = dp[0];
        dp[0] = profit;
    }
    
    return dp[0] > 0;
}
