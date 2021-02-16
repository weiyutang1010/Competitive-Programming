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
    array<int, 1000001> cnt {0}; // Store all divisor
 
    // Store all factor into cnt O(n sqrt(x))
    // Find largest factor from cnt O(n)
 
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
 
        // For each factor
        for (int j = 1; j * j <= x; j++) {
            // add factor into mp
            if (x % j == 0) {
                cnt[j]++;
                // ignore if it is square
                if (j * j != x) {
                    cnt[x / j]++;
                }
            }
        }
    }
 
    // Find largest factor in mp such that count > 1
    for (int i = 1000000; i >= 1; i--) {
        if (cnt[i] > 1) {
            cout << i << endl;
            break;
        }
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