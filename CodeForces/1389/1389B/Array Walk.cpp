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

ll n, k, z;
ll dp [100002][6];

ll func(vector<int> &v, int i, int mov, int left) {
    if (mov == 0 || i >= n || i < 0) {
        return 0;
    }
    
    if (dp[i][left] != -1) {
        return dp[i][left];
    }
    
    ll val = 0;
    if (i < n) {
        val = max(val, v[i] + func(v, i + 1, mov - 1, left));
    }
    
    if (i >= 0 && left > 0) {
        val = max(val, v[i] + func(v, i - 1, mov - 1, left - 1));
    }
    
    return dp[i][left] = val;
}

void solve() {
    cin >> n >> k >> z;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    memset(dp, -1, sizeof(dp));
    ll ans = func(v, 1, k, z) + v[0];
    
    cout << ans << endl;
}    

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 