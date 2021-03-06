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
    for (int& x: v) cin >> x;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1] * 2) {
            int val = v[i - 1];
            while (val * 2 < v[i]) {
                val *= 2; 
                ans++;
            }
        } else if (v[i - 1] > v[i] * 2) {
            int val = v[i];
            while (val * 2 < v[i - 1]) {
                val *= 2; 
                ans++;
            }
        }
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
