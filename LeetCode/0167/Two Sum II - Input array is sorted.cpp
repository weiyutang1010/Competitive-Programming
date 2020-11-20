class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) {
        unordered_map<int, int> m;
        m[nums[0]] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (m[tgt - nums[i]]) {
                return vector<int> {m[tgt - nums[i]], i + 1};
            }
            m[nums[i]] = i + 1;
        }
        
        return vector<int> {0, 0};
    }
};