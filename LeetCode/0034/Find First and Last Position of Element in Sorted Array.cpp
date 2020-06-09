//Explanation: Have one pointer at the start and one at the end
//             Increment the first point and decrement the second point
//             until they both reach the target number
//             Return the index of both numbers

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = 0;
        int idx2 = nums.size() - 1;
        
        if (nums.size() == 1) {
            vector<int> ans;
            if (nums[0] == target) {
                vector<int> ans {0, 0};
                return ans;
            } else {
                vector<int> ans {-1, -1};
                return ans;
            }
        }
        
        
        while(idx2 >= idx1) {
            if (nums[idx2] != target) {
                idx2--;
            }
            if (nums[idx1] != target) {
                idx1++;
            }
            
            if (nums[idx1] == target && nums[idx2] == target) {
                break;
            }
        }
        
        if (idx2 < idx1) {
            idx1 = -1;
            idx2 = -1;
        }
        
        vector<int> ans {idx1, idx2};
        return ans;
    }
};