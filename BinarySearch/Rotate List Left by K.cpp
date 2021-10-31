vector<int> solve(vector<int>& nums, int k) {
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
    return nums;
}
