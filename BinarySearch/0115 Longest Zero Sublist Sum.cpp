#define f first
#define s second

int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);
    prefix_sum[0] = 0;
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(0);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        mp[prefix_sum[i]].push_back(i);
    }

    int max_n = 0;
    for(auto& x: mp) {
        if (x.s.size() > 1) {
            max_n = max(max_n, x.s[x.s.size() - 1] - x.s[0]);
        }
    }

    return max_n;
}