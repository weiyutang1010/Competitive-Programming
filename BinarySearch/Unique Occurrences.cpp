bool solve(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    unordered_map<int, int> cnt;
    for (auto& x: mp) {
        cnt[x.second]++;
        if (cnt[x.second] > 1) {
            return false;
        }
    }
    return true;
}