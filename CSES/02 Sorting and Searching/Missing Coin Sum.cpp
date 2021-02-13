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
    vector<int64_t> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + v[i];
    }
 
    if (v[0] != 1) {
        cout << 1 << endl;
        return;
    }
 
    int64_t curr = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] > curr + 1) {
            cout << curr + 1 << endl;
            return;
        }
 
        curr = v[i] + prefix_sum[i];
    }
    cout << curr + 1 << endl;
 
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