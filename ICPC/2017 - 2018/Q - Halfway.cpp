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
    ll n;
    cin >> n;

    // Total number of comparison
    ll comp = (n * (n - 1)) / 2;
    // Find printed value at idx number
    ll idx;
    if (comp & 1) {
        idx = (comp + 1) / 2;
    } else {
        idx = comp / 2;
    }

    for (int i = 1; i < n; i++) {
        ll nums = n - i;
        if (idx <= nums) { 
            cout << i << endl;
            return;
        }
        idx -= nums;
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
