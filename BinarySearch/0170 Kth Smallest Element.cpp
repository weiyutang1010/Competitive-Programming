int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start], j = end;
    // swap everything smaller than pivot to the left
    for (int i = start + 1; i <= j;) {
        if (nums[i] >= pivot) {
            swap(nums[i], nums[j--]);
        } else {
            i++;
        }
    }
    // swap pivot so everything before pivot is smaller than pivot
    swap(nums[start], nums[j]);
    return j;
}

int solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    // Binary search
    while (l <= r) {
        // Instead of mid, get index m such that everything
        // before m is smaller than nums[m]
        int m = partition(nums, l, r);

        if (m == k) {
            return nums[m];
        } else if (m > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    // should not reach here
    return 0;
}