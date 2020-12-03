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
 
struct comp {
    bool operator()(const int& a, const int& b) {
        return a <= b;
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
 
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), v[i], comp()); 
 
        if (it == ans.end()) {
            ans.push_back(v[i]);
        } else {
            *it = v[i];
        }
 
    }
 
    cout << ans.size() << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 