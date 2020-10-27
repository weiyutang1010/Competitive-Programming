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

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> p;
    vector<int> a(n);
    vector<pair<int64_t, int64_t>> dp(n, make_pair(0, 0));

    int temp = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> temp;
        p[temp - 1].push_back(i + 1);
    }

    for (int& x: a) {
        cin >> x;
    }

    function<void (int)> dfs = [&](int idx) -> void {
        pair<int64_t, int64_t> ans = {a[idx], 0};

        for (int& x: p[idx]) {
            dfs(x);
            ans.f += dp[x].f;
            ans.s += dp[x].s;
        }

        ans.s = max((ll)ans.s, 1LL);

        dp[idx] = ans;
        return;
    };

    dfs(0);
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (int64_t)ceil((ld)dp[i].f / dp[i].s));
    }
    cout << ans << endl;


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
