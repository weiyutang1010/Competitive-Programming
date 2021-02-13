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
 
const int INF = 1e9;
 
void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
 
    unordered_map<int, int> visited;
 
    // for (auto x: m) {
    //     cout << x.f << ": ";
    //     for (auto y: x.s) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
 
    function<int (int)> dfs = [&](int val) -> int {
        int ans = 0;
        bool has_odd = 0;
        bool has_child = 0;
        for (int& node: m[val]) {
            if (!visited[node]) {
                has_child = 1;
                visited[node] = 1;
                int num = dfs(node);
                if (num & 1) {
                    num--;
                    has_odd = 1;
                }
                ans += num;
            }
        }
 
        if (!has_child) {
            return 1;
        }
 
        //cout << "val: " << val << " has_odd: " << has_odd << " ans: " << ans << endl;
 
        if (has_odd) {
            return ans + 2;
        } else {
            return ans + 1;
        }
    };
 
    int ans = 0;
    for (auto x: m) {
        visited[x.f] = 1;
        ans = dfs(x.f);
        break;
    }
 
    cout << ans / 2 << endl;
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