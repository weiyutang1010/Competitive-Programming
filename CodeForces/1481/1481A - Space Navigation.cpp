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
    int x, y;
    cin >> x >> y;
    string st;
    cin >> st;

    map<char, int> m;
    for (char& c: st) {
        m[c]++;
    }

    bool a = false, b = false;
    if (x >= 0 && m['R'] >= x) {
        a = true;
    } else if (x <= 0 && m['L'] >= abs(x)) {
        a = true;
    }

    if (y >= 0 && m['U'] >= y) {
        b = true;
    } else if (y <= 0 && m['D'] >= abs(y)) {
        b = true;
    }

    if (a && b) cout << "YES" << endl;
    else cout << "NO" << endl;
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
