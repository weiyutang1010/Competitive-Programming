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
#define int int64_t

using namespace std; 
 
const int MOD = 1e9 + 7;

vector<vector<int>> v(3);

int calc(vector<int>& n) {
    int ans = 0, m1 = v[1][0], m2 = v[2][0], s1 = 0, s2 = 0;
    for (int i : v[0]) ans += i;
    for (int i = 1; i < n[1]; i++) s1 += v[1][i];
    for (int i = 1; i < n[2]; i++) s2 += v[2][i];

    ans += max({s2-m1+s1-m2, m2+s2-m1-s1, m1+s1-m2-s2});
    return ans;
}

void solve() {
    vector<int> n(3, 0);
    cin >> n[0] >> n[1] >> n[2];

    v[0].resize(n[0]);
    v[1].resize(n[1]);
    v[2].resize(n[2]);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }

    int ans = INT_MIN;
    ans = max(ans, calc(n));

    swap(v[0], v[1]), swap(n[0], n[1]);
    ans = max(ans, calc(n));

    swap(v[0], v[2]), swap(n[0], n[2]);
    ans = max(ans, calc(n));

    cout << ans << endl;
}
 
signed main() 
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
