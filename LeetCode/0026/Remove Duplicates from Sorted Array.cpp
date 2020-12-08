class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pt = 1;
        int sz = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                sz--;
            } else {
                nums[pt] = nums[i];
                pt++;
            }
        }
        return sz;
    }
};