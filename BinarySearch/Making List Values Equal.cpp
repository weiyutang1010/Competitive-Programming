int solve(vector<int>& nums) {
    int max_n = *max_element(nums.begin(), nums.end());
    int min_n = *min_element(nums.begin(), nums.end());
    return max_n - min_n;
}