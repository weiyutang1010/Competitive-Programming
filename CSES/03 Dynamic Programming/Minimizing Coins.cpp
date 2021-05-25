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

const int INF = 1e9;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }

    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for (int i = 1; i < x + 1; i++) {
        for (int& coin: v) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[x] < INF) {
        cout << dp[x] << endl;
    } else {
        cout << -1 << endl;
    }
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
