//Practice binary search (works on sorted array)
//Find the mid element (if equal target then return mid index)
//Check if target is to the left or right of mid element
//If it is to the left, move right pointer to mid - 1
//Else move left pointer to mid + 1
//Repeats

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si = 0;
        int ei = nums.size() - 1;
        while (ei >= si) {
            int mid = (si + ei) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                si = mid + 1;
            } else {
                ei = mid - 1;
            }    
        }
        return -1;
    }
};