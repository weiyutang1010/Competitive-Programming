bool solve(vector<int>& nums) {
    int n = nums.size();

    if (nums[1] <= nums[0]) return false;

    for (int i = 2; i < n; i++) {
        if (nums[i] == nums[i-1]) {
            return false;
        }
    }

    return true;
}
