/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
 
using namespace std; 
 
const int MOD = 1e9 + 7;
 
void solve() {
    int n, amount;
    cin >> n >> amount;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
 
    sort(v.begin(), v.end());
 
    vector<int64_t> dp(amount + 1, 0);
    dp[0] = 1;
 
    for (int& coin: v) {
        for (int i = 1; i <= amount; i++) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin] % MOD;
            }
        }
    }
 
    cout << dp[amount] % MOD << endl;
 
 
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 