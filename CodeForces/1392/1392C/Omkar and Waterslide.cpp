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
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
    
    int max_n = v[0], min_n = v[0];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            ans += max_n - min_n;
            max_n = v[i];
            min_n = v[i];
        }

        max_n = max(max_n, v[i]);
        min_n = min(min_n, v[i]);
    }
    ans += max_n - min_n;

    cout << ans << endl;
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
