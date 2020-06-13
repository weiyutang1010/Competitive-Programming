class Solution {
public:
    int maxProduct(vector<int>& nums) {
        pair<int,int> max1 {0, 0};
        int max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max1.first < nums[i]) {
                max1.first = nums[i];
                max1.second = i;
            }           
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i != max1.second && max2 < nums[i]) {
                max2 = nums[i];
            }
        }
        
        return ((max1.first - 1) * (max2 - 1));
    }
};