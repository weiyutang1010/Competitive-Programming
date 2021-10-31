#define f first
#define s second

// O(n) Solution
// Note: Start from pos, each loop, we move bracket 1 step towards larger value. Then check the answer.
int solve(vector<int>& nums, int pos) {
    int n = nums.size();
    int l = pos, r = pos;
    int currMin = nums[pos];
    int ans = INT_MIN;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, currMin * i);

        int left = ((l - 1 >= 0) ? nums[l-1] : INT_MIN);
        int right = ((r + 1 < n) ? nums[r+1] : INT_MIN);

        if (left > right) {
            currMin = min(currMin, left);
            l--;
        } else {
            currMin = min(currMin, right);
            r++;
        }
    }

    return ans;
}
