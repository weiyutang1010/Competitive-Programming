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
    string a, b;
    cin >> a >> b;

    if (a[0] != b[0]) {
        cout << -1 << endl;
        return;
    }

    string s1 = a, s2 = b;
    int i = 0;
    while (s1.size() != s2.size() && i < 1000) {
        if (s1.size() < s2.size()) {
            s1 += a;
        } else if (s1.size() > s2.size()) {
            s2 += b;
        }

        i++;
    }

    if (s1 == s2) {
        cout << s1 << endl;
    } else {
        cout << -1 << endl;
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
