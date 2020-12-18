#define f first
#define s second

class Solution {
public:
    int maxHeight(vector<vector<int>>& A) {
        // rotate cuboids so height is the greatest
        for (auto& c: A) {
            sort(c.begin(), c.end());
        }
        // sort cuboids from small to large
        A.push_back({0, 0, 0});
        sort(A.begin(), A.end());
        
        int n = A.size(), ans = 0;
        vector<int> dp(n);
        // dp[i] is the max height for placing cuboids[i]
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i ; j++) {
                if (A[j][0] <= A[i][0] && A[j][1] <= A[i][1] && A[j][2] <= A[i][2]) {
                    dp[i] = max(dp[i], dp[j] + A[i][2]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};