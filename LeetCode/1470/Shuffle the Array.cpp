//Explanation: Make a new array. Alternate inserting the first element and element from midpoint onwards

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int j = nums.size() / 2;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            j++;
        }
        
        return ans;
    }
};