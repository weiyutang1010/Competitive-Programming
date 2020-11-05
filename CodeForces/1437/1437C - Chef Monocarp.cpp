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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    sort(v.begin(), v.end());
    vector<vector<int>> dp(n + 1, vector<int> (2 * n, INF));

    dp[0][0] = 0;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            if (dp[i][j] < INF) {
                if (i < n) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(v[i] - j));
                }
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }

    cout << dp[n][2 * n - 1] << endl;
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
