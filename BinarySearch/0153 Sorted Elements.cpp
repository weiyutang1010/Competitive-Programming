int solve(vector<int>& nums) {
    vector<int> v(nums);
    sort(v.begin(), v.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == nums[i]) ans++;
    }
    return ans;
}