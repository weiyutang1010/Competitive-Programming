class Solution {
public:
    vector<int> ans;
    bool found = false;
    
    void backtracking(vector<int> v, map<int, int> nums, int n, int idx) {
        if (idx == n * 2 - 1) {
            bool cond1 = true;
            for (auto& num: nums) {
                if (num.second != 0) {
                    cond1 = false;
                    break;
                }
            }
            
            if (cond1) {
                ans = v;
                found = true;
            }
            return;
        }
        
        if (v[idx] != 0) {
            backtracking(v, nums, n, idx + 1);
            return;
        }
        
        for (int i = n; i > 0; i--) {
            if (i != 1) {
                if (nums[i] && idx + i < n * 2 - 1 && v[idx + i] == 0) {
                    v[idx] = i;
                    v[idx + i] = i;    
                    nums[i] = 0;
                    backtracking(v, nums, n, idx + 1);
                    nums[i] = 1;
                    v[idx + i] = 0;    
                } 
            } else if (nums[i] && i == 1) {
                v[idx] = i;
                nums[i] = 0;
                backtracking(v, nums, n, idx + 1);
                nums[i] = 1;
                break;
            }

            if (found) {
                return;
            }
        }
    }
    
    vector<int> constructDistancedSequence(int n) {
        if (n == 1) {
            return vector<int> (1, 1);
        }
        
        vector<int> v(n * 2 - 1, 0);
        ans.resize(n * 2 - 1, 0);
        map<int, int> nums;
        for (int i = 1; i <= n; i++) {
            nums[i] = 1;
        };
        backtracking(v, nums, n, 0);
        return ans;
    }
};