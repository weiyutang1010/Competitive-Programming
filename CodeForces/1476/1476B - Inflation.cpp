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
    ld n, k;
    cin >> n >> k;
    vector<ld> v(n);
    for (ld& x: v) {
        cin >> x;
    }

    ld ans = 0, sum = v[0];
    for (int i = 1; i < n; i++) {
        ld val = v[i] / (sum + ans);
        if (val > (k / 100)) {
            ld temp = (100 * v[i] - k * (sum + ans)) / k;
            ans += ceil(temp);
        }
        sum += v[i];
    }

    cout << (int64_t)ans << endl;
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
