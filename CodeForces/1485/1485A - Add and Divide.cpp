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
    int a,b;
    cin >> a >> b;

    int ans = INT_MAX;

    for (int i = b; i - b < ans; i++) {
        if (i == 1) continue;
        int curr = 0;
        int val = a;

        while (val > 0) {
            val /= i;
            curr++;
        }
        ans = min(curr + i - b, ans);
    }

    cout << ans << endl;
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
