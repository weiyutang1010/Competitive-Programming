vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> peaks;

    if (n == 1) return peaks;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 && nums[i] > nums[i + 1]) {
            peaks.push_back(i);
        } else if (i == n - 1 && nums[i] > nums[i - 1]) {
            peaks.push_back(i);
        } else if (nums[i] > nums[i-1] &&
                    nums[i] > nums[i+1]) {
                        peaks.push_back(i);
                    }
    }

    return peaks;
}