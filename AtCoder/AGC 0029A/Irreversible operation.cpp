#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    string s;
    cin >> s;

    if (s.size() < 2) {
        cout << 0 << endl;
        return;
    }

    int seen = 0;
    ll ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'W') {
            ans += i - seen;
            seen++;
        }
    }

    cout << ans << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
