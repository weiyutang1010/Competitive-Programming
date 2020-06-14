class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(),1);
        
        int max_num = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    max_num = max(max_num, dp[i]);
                    //break;
                }
            }
        }
        cout << "max: " << max_num << endl;
        
        vector<int> ans(max_num);
        int prev = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (dp[i] == max_num && (prev == -1 || prev % nums[i] == 0)) {
                ans[max_num - 1] = nums[i];
                prev = nums[i];
                max_num--;
            }
        }
        
        return ans;
    }
};