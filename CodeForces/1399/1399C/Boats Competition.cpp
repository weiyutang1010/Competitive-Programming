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

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    
    map<int, int> ans;
    int max_ans = 0;
    for (auto x: m) {
        for (auto y: m) {
            if (x.f == y.f) {
                ans[2 * x.f] += (x.s / 2) * 2;
                max_ans = max(ans[2*x.f], max_ans);
            } else {
                ans[x.f + y.f] += min(x.s, y.s);
                max_ans = max(ans[x.f + y.f], max_ans);
            }
        }
    }
    cout << max_ans/2 << endl;
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
