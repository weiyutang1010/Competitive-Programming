class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v (heights.begin(),heights.end());
        sort(v.begin(), v.end());
        
        int ans = 0;
        for (int i = 0; i < (int)heights.size(); i++) {
            if (heights[i] != v[i]) {
                ans++;
            }
        }
        
        return ans;
    }
};