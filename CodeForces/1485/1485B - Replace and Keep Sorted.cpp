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
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> v(n);
    for (int& x: v) cin >> x;

    int l, r;
    for (int i = 0; i < q; i++) {
        int ans = 0;
        cin >> l >> r;
        l--; r--;

        if (r == l) {
            cout << k - 1 << endl;
            continue;
        }

        // 0 to l
        ans += max(0, v[l] - 1);
        
        // r to k
        ans += k - v[r];
        
        // middle
        ans += ((v[r] - v[l] - 1) - (r - l - 1)) * 2;

        cout << ans << endl;
    }
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    // cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
