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
    int64_t w, h, n;
    cin >> w >> h >> n;

    int64_t ans = 0;
    int64_t val1 = 1, val2 = 1;
    if (!(w & 1)) val1 = (w & -w);
    if (!(h & 1)) val2 = (h & -h);

    ans = val1 * val2;
    if (ans >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
