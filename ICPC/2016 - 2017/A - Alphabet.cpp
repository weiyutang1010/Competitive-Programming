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
    string s;
    cin >> s;
    int n = s.size();

    int max_n = 0;
    vector<int> v(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i]) {
                v[i] = max(v[j] + 1, v[i]);
                max_n = max(max_n, v[i]);
            }
        }
    }

    max_n = max(1, max_n);
    max_n = min(26, max_n);
    cout << 26 - max_n << endl;
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
