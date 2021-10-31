vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    int pt1 = 0;
    int zero = 0;

    // two pt approach
	for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[pt1] = nums[i];
            pt1++;
        } else {
            zero++;
        }
    }

    for (int i = n - 1; i > n - 1 - zero; i--) {
        nums[i] = 0;
    }

    return nums;
}
