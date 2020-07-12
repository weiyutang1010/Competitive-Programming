#define ll long long
#define ld long double

const int MOD = 1e9+7;

class Solution {
public:
    int numSub(string s) {
        ll cnt = 0;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') {
                cnt = (cnt + 1) % MOD;
            }
            
            if (s[i] == '0' || i == (int)s.size() - 1) {
                if (cnt > 0) {
                    ans = (ans % MOD) + (((cnt * (cnt+1)) / 2) % MOD);
                    cnt = 0;
                }
            }
        }
        
        return ans;
    }
};