class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (right >= left) {
            int mid = left + (right - left) / 2;
            int mid_n = nums[mid];
            int left_n = nums[left]; //current left number
            int right_n = nums[right]; //current right number
            
            if (mid_n == target) {
                return mid;
            }
            
            if (mid_n > right_n) { //mid element is at left of pivot
                if (target >= left_n && target < mid_n) { //check if target is between current value and left element
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (mid_n < left_n) { //mid element is at the right of pivot
                if (target <= right_n && target > mid_n) {  //check if target is between current value and right element
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { //When the array sorted, perform normal binary search
                if (mid_n < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};