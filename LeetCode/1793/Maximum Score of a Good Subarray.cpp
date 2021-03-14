class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return nums[0];
        
        // left[i] contains the first number that is smaller than nums[i] to the left
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            int lt = i - 1;
            while (lt > -1 && nums[lt] >= nums[i]) lt = left[lt];
            left[i] = lt;
        }
        
        // right[i] contains the first number that is smaller than nums[i] to the right
        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            int rt = i + 1;
            while (rt < n && nums[rt] >= nums[i]) rt = right[rt];
            right[i] = rt;
        }
        
        // The min between left[i] and right[i], exclusive, is nums[i]
        // The length between left[i] and right[i] is (right[i] - 1) - (left[i] + 1) + 1
        int ans = nums[k];
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                ans = max(ans, ((right[i] - 1) - (left[i] + 1) + 1) * nums[i]);
            }
        }
        
        return ans;
    }
};