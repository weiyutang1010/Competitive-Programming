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

void dfs(vector<int>& ans, const vector<int>& v, int l, int r, int depth) {
    if (r < l) return;
    if (l < 0 || r >= (int)v.size()) return;

    if (l == r) {
        ans[l] = depth;
        return;
    }

    // Find index of largest value
    ii max_idx {0, 0};
    for (int i = l; i <= r; i++) {
        if (v[i] > max_idx.f) {
            max_idx = {v[i], i};
        }
    }

    ans[max_idx.s] = depth;

    dfs(ans, v, l, max_idx.s - 1, depth + 1);
    dfs(ans, v, max_idx.s + 1, r, depth + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) cin >> x;

    vector<int> ans(n, 0);
    dfs(ans, v, 0, n - 1, 0);

    for (int& x: ans) {
        cout << x << " ";
    }
    cout << endl;
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
