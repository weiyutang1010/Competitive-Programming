int solve(vector<int>& nums) {
    // Use a map to count each element
    unordered_map<int, int> mp;
    int ans = 0; // keep track of max count in the map
    for (int& x: nums) {
        mp[x]++;
        ans = max(ans, mp[x]);
    }
    return ans;
}