// Possible to do in O(n) by just finding top 2 values
bool solve(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    return nums[n - 1] > (nums[n - 2] * 2);
}