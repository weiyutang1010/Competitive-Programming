#define ii pair<int, int>
#define f first
#define s second

class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        // dp pair contains { longest increasing length, number of path }
        vector<ii> dp (v.size(), make_pair(1, 1));
        int curr_max = 1; 
        for (int i = 1; i < v.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (v[j] < v[i]) {
                    if (dp[j].f + 1 > dp[i].f) {
                        dp[i].f = dp[j].f + 1;
                        dp[i].s = dp[j].s;
                        curr_max = max(curr_max, dp[i].f);
                    } else if (dp[j].f + 1 == dp[i].f) {
                        dp[i].s += dp[j].s;
                    }
                }
            }
        }
        
        int ans = 0;
        for (auto x: dp) {
            if (x.f == curr_max) {
                ans += x.s;
            }
        }
        
        return ans;
    }
};