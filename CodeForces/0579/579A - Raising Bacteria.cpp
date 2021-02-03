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
    int x;
    cin >> x;

    // Find all power of two such that they add up to x and each power of two is to the largest
    int64_t ans = 0;
    while (x > 0) {
        int64_t twos = 1;
        while (twos * 2 <= x) {
            twos *= 2;
        }
        ans++;
        x -= twos;
    }

    cout << ans << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    // cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
