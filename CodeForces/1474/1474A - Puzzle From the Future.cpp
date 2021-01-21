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
    string s;
    cin >> s;

    string ans = "1";
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i] != s[i - 1]) {
            ans += '1';
        } else if (s[i] != s[i - 1]) {
            ans += ans[i - 1];
        } else {
            ans += (ans[i-1] == '1')? '0' : '1';
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
