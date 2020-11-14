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
    int n, x;
    cin >> n >> x;
    vector<int>v(n);
    for (int& x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
 
    int lt = 0, rt = n - 1;
    int64_t ans = 0;
    while (lt <= rt) {
        int curr = v[rt];
        rt--;
        if (lt <= rt && curr + v[lt] <= x) {
            curr += v[lt];
            lt++;
        }
        ans++;
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