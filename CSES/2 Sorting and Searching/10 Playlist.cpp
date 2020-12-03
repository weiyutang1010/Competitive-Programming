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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
    map<int, int> m;
 
    int ans = 0;
    int lt = 0;
    for (int i = 0; i < n; i++) {
        if (m[v[i]]) {
            lt = max(lt, m[v[i]]);
        }
        m[v[i]] = i + 1;
        ans = max(ans, i - lt + 1);
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