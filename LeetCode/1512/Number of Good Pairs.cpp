class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        map<int, int> cnt;
        for (auto x: nums) {
            cnt[x]++;
        }
        
        for(auto x: cnt) {
            int n = x.second;
            if (n > 1) {
                ans += (n * (n - 1)) / 2;
            }
        }
        
        return ans;
        
        
    }
};