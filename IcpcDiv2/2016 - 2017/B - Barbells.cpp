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

void backtrack(set<int>& ans, vector<int>& b, int left, int right, vector<int>& p, int idx) {
    if (left == right) {
        for (int& x: b) {
            ans.insert(x + left + right);
        }
    }

    if (idx >= (int)p.size()) return;
    
    int curr = p[idx];
    backtrack(ans, b, left + curr, right, p, idx + 1);
    backtrack(ans, b, left, right + curr, p, idx + 1);
    backtrack(ans, b, left, right, p, idx + 1);
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n), p(m);
    for (int& x: b) cin >> x;
    for (int& x: p) cin >> x;
    
    set<int> ans;
    backtrack(ans, b, 0, 0, p, 0);

    for (const int& x: ans) {
        cout << x << endl;
    }
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    //cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
