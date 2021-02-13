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
    ll y, x;
    cin >> y >> x;

    ll val_y = ((y & 1)? ((y - 1) * (y - 1) + 1) : (y * y));
    ll val_x = ((x & 1)? (x * x) : ((x - 1) * (x - 1) + 1));

    if (y == x) {
        cout << (val_y + val_x) / 2 << endl;
    } else if (y - x > 0) {
        cout << val_y + ((y & 1) ? (x - 1) : (-x + 1)) << endl;
    } else {
        cout << val_x + ((x & 1) ? (-y + 1) : (y - 1)) << endl;
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
