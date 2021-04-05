int solve(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (to_string(nums[i]).size() & 1) {
            ans++;
        }
    }
    return ans;
}