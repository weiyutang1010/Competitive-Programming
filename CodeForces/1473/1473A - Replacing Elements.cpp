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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);

    bool larger = false;
    for (int& x: v) {
        cin >> x;
        if (x > d) {
            larger = true;
        }
    }

    if (!larger) {
        cout << "YES" << endl;
        return;
    }

    sort (v.begin(), v.end());

    if (v[0] + v[1] > d) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
