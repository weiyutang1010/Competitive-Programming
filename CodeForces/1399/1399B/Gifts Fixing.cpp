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
    vector<int> a(n);
    vector<int> b(n);

    int min_a = INT_MAX, min_b = INT_MAX;
    for (int& x: a) {
        cin >> x;
        min_a = min(min_a, x);
    }
    for (int& y: b) {
        cin >> y;
        min_b = min(min_b, y);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > min_a && b[i] > min_b) {
            int temp_a = a[i] - min_a;
            int temp_b = b[i] - min_b;
            int small = min(temp_a, temp_b);
            ans += small;
            ans += max(temp_a, temp_b) - small;
        } else if (a[i] > min_a) {
            ans += a[i] - min_a;
        } else if (b[i] > min_b) {
            ans += b[i] - min_b;
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
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
