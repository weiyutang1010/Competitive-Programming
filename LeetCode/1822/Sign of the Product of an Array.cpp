class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num_neg = 0;
        // Check for any 0 and count number of negative values
        for (int i = 0;i < (int)nums.size(); i++) {
            if (nums[i] < 0) {
                num_neg++;
            } else if (nums[i] == 0) {
                return 0;
            }
        }
        
        if (num_neg & 1) {
            return -1;
        }
        return 1;
    }
};