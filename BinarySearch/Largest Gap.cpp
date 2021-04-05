int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max_n = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        max_n = max(max_n, nums[i+1] - nums[i]);
    }
    return max_n;
}