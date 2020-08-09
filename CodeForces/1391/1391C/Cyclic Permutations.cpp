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
    int MOD = 1e9 + 7;

    ll left = 1, right = 2;
    for (int i = n; i > 0; i--) {
        left = (left * i) % MOD;
    }

    for (int i = 1; i < n - 1; i++) {
        right = (right * 2) % MOD;
    }

    cout << ((left - right) + MOD) % MOD << endl;
    
}    

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
