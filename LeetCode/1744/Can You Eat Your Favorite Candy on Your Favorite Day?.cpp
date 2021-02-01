class Solution {
public:
    vector<bool> canEat(vector<int>& C, vector<vector<int>>& Q) {
        vector<long long> prefix_sum (C.size() + 1, 0);
        for (int i = 1; i < (int)C.size() + 1; i++) {
            prefix_sum[i] = C[i - 1] + prefix_sum[i - 1];
        }
        
        
        vector<bool> ans(Q.size());
        for (int i = 0; i < (int)Q.size(); i++) {
            long long type = Q[i][0], day = Q[i][1], atmost = Q[i][2];
            if ((day + 1) * atmost > prefix_sum[type] && prefix_sum[type + 1] >= (day + 1)){
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        
        return ans;
    }
};