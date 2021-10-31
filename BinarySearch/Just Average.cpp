bool solve(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;

    int curr = 0;
    for (int& x: nums) {
        mp[x]++;
        curr += x;
    }

    int target = (n-1) * k;

    return mp[curr - target];
}
