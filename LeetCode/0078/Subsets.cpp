class Solution {
public:
    void recursion(vector<vector<int>>& ans, vector<int> subset, vector<int>& nums, int curr_idx, int size) {
        if (curr_idx > size) {
            return;
        }
        
        ans.push_back(subset);
        
        for (int i = curr_idx; i < size; i++) {
            subset.push_back(nums[i]);
            recursion(ans, subset, nums, i + 1, size);
            subset.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(ans, vector<int> (), nums, 0, nums.size());
        return ans;
    }
};