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
    ll x;
    cin >> x;

    map<ll, int> cube;
    for (ll curr = 1; curr <= 10000; curr++) {    
        ll val = curr * curr * curr;
        if (val >= x) break; 
        cube[val] = 1;
    }

    for (auto& y: cube) {
        if (cube[y.f] && cube[x - y.f]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
