class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n ; j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0;
        for (auto& x: m) {
            if (x.second >= 2) {
                int pairs = (x.second * (x.second - 1)) / 2;
                ans += pairs * 8;
            }
            // cout << x.first << " " << x.second << endl;
        }
        cout << endl;
        return ans;
    }
};