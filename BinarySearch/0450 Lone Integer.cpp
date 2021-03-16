// There's a bit manipulation answer

int solve(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    if (nums[0] != nums[1] && nums[0] != nums[2]) return nums[0];
    if (nums[n - 1] != nums[n - 2] && nums[n - 1] != nums[n - 3]) return nums[n - 1];

    for (int i = 1; i < n - 1; i++) {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }

    return nums[0];
}