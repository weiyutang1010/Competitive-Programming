bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int step = nums[1] - nums[0];
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i - 1] != step) {
            return false;
        }
    }
    return true;
}