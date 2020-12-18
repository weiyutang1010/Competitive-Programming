class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        // Create prefix sum array
        vector<int> sum(n + 1, 0);
        for (int i = 1; i < n + 1; i++) sum[i] = sum[i - 1] + stones[i - 1];
        
        // DP where dp[i][j] is the max difference a player can get for stones[i ... j]
        vector<vector<int>> dp (n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // max_difference = my_score + amount - his score
                //                = amount - (his score - my score)
                //                = amount - dp[i][j]
                // max(if we choose left stone, if we choose right stone)
                dp[i][j] = max(sum[j+1] - sum[i+1] - dp[i+1][j], 
                               sum[j] - sum[i] - dp[i][j-1]);
            }
        }
        
        return dp[0][n - 1];
    }
};