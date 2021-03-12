int solve(int k, vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || k == 0) return 0;
    unordered_map<int, int> mp;

    int ans = 0;
    int distinct = 0;
    int l, r;

    // Add in the first value
    mp[nums[0]]++;
    distinct = 1;

    for (l = 0, r = 0; l < n && r < n;) {
        while (r + 1 < n && distinct <= k) {
            if (distinct == k && !mp[nums[r + 1]]) {
                break;
            }
            if (!mp[nums[r + 1]]) {
                distinct++;
            }
            mp[nums[r + 1]]++;
            r++;
        }

        ans = max(ans, r - l + 1);
        mp[nums[l]]--;
        if (mp[nums[l]] == 0) distinct--;
        l++;
    }
    return max(ans, r - l + 1);
}