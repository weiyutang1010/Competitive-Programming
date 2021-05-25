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
 
    vector<int64_t> dp(amount + 1, 0);
 
    for (int i = 0; i < n; i++) {
        if (v[i] < amount + 1) {
            dp[v[i]] = 1;
        }
    }
 
    for (int i = 1; i <= amount; i++) {
        for (int& coin: v) {
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