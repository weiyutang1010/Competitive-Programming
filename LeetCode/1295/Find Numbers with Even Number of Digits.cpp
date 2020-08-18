class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int limit = 1e7;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            bool even_digit = 0;
            for (int j = 10; j < limit; j *= 10) {
                if (nums[i] < j) {
                    ans += even_digit;
                    break;
                } else {
                    even_digit = !even_digit;
                }
            }    
        }
        return ans;
    }
};