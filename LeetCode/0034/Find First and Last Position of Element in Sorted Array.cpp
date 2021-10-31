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

// Solution 2
// Use Binary Search twice to find left and right indexes.

class Solution {
public:
    int bin_search(vector<int>& nums, int target, int temp, int temp2) {
        // temp indicates whether check left or right
        // temp2 indicates which end of array to check
        
        int n = nums.size();
        if (n < 1) return -1;
        
        int lt = 0, rt = n - 1;
        while (lt <= rt) {
            int mid = (lt + rt) / 2;
            
            if (nums[mid] == target) {
                if (mid == temp2) return mid;
                else if (nums[mid+temp] != target) return mid;
                else {
                    if (temp == -1) {
                        rt = mid - 1;
                    } else {
                        lt = mid + 1;
                    }
                }
            } else if (nums[mid] > target) {
                rt = mid - 1;
            } else {
                lt = mid + 1;
            }
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {        
        int n = nums.size();
        return vector<int> {bin_search(nums, target, -1, 0), bin_search(nums, target, 1, n-1)};
    }
};
