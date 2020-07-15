#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 

void solve() {
    int n;
    cin >> n;
    
    vector<ll> dp(n+1, 0);
    vector<int> dices {1, 2, 3, 4, 5, 6};
    dp[0] = 1;

    for (int i = 1; i < n+1; i++) {
        for (auto x: dices) {
            if (i >= x) {
                dp[i] += dp[i - x] % 1000000007;
            }
        }
    }
    cout << dp[n] % 1000000007 << "\n";
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
