vector<vector<int>> solve(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    if (n == 0) return ans;
    ans.push_back({nums[0]});

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            ans[ans.size() - 1].push_back(nums[i]);
        } else {
            ans.push_back({nums[i]});
        }
    }
    return ans;
}