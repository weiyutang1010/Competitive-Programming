vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> v(n);
    for (int i = 0, j = n - 1; i < n; i += 2, j--) {
        v[i] = nums[j];
    }

    for (int i = 1, j = 0; i < n; i += 2, j++) {
        v[i] = nums[j];
    }

    return v;
}
