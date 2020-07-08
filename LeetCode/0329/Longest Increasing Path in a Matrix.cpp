#define ii pair<int, int>
#define f first
#define s second

vector<ii> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

class Solution {
public:  
    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, int max_length, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        
        int ans = max_length;
        for (ii&  d: dir) {
            if (i + d.f >= 0 && j  + d.s >= 0 && i + d.f < n && j + d.s < m) {
                if (matrix[i + d.f][j + d.s] > matrix[i][j]) {
                    ans = max(ans, 1 + dfs(matrix, i+d.f, j+d.s, n, m, max_length, dp));
                }
            }
        }
        
        dp[i][j] = ans;
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() < 1) {
            return 0;
        }
        
        int ans = 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp (n, vector<int> (m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp = dfs(matrix, i, j, n, m, 1, dp);
                ans = max(ans, temp);
            }
        }
        
        return ans;
    }
};