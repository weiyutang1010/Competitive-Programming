#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() 
{ 
    int x = 0, y = 0;
    cin >> x >> y;
    
    int ans = x;
    int m = sqrt(x);
    for (int i = 1; i <= m && i <= y; i++) {
        if (x % i == 0) {
            ans = min(ans, x/i);
            if (x/i <= y) {
                ans = min(ans, i);
            }
        }
    }
    
    cout << ans << "\n";
} 