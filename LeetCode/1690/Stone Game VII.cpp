class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            sum[i] = sum[i - 1] + stones[i - 1];
        }
        
        vector<vector<int>> dp (n, vector<int> (n));
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                int k = i + j - 1;
                dp[j][k] = max(sum[k + 1] - sum[j + 1] - dp[j + 1][k], sum[k] - sum[j] - dp[j][k - 1]);
            }
        }
        
        return dp[0][n - 1];        
    }
};