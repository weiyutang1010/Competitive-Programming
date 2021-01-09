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
    for (int& x: v) {
        cin >> x;
    }

    sort(v.rbegin(), v.rend());
    vector<int64_t> res = {0, 0};
    for (int i = 0; i < n; i++) {
        if (v[i] & 1 && i & 1) {
            res[1] += v[i];
        } else if (!(v[i] & 1) && !(i & 1)) {
            res[0] += v[i];
        }
    }

    if (res[0] == res[1]) {
        cout << "Tie" << endl;
    } else if (res[0] > res[1]) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
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
