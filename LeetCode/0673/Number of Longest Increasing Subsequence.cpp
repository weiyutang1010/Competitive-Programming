#define ii pair<int, int>
#define f first
#define s second

class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        // dp pair contains { longest increasing length, number of path }
        vector<ii> dp (v.size(), make_pair(1, 0));
        int curr_max = 0; 
        for (int i = 1; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (v[j] < v[i]) {
                    dp[i].f = max(dp[i].f, dp[j].f + 1);
                    curr_max = max(curr_max, dp[i].f);
                }
            }
            
            for (int j = 0; j < i; j++) {
                if (v[j] < v[i] && dp[j].f + 1 == dp[i].f) {
                    dp[i].s += (dp[j].s == 0 ? 1 : dp[j].s);
                }
            }
        }

        
        int ans = 0;
        for (auto x: dp) {
            if (x.f == curr_max) {
                ans += x.s;
            }
        }
        
        return (ans == 0 ? v.size() : ans);
    }
};