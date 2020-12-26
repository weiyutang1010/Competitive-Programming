class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        
        //Get sum of abs diff for first value
        for (int i = 1; i < (int)nums.size(); i++) {
            ans[0] += nums[i] - nums[0];
        }
        
        //Calculate sum of abs diff for the rest of values
        for (int i = 1; i < (int)nums.size(); i++) {
            ans[i] = ans[i - 1] + (nums[i] - nums[i - 1]) * i - (nums[i] - nums[i - 1]) * (nums.size() - i);
        }
        
        return ans;
    }
};