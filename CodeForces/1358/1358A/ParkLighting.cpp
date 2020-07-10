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
    int n, m;
    cin >> n >> m;
    
    if ((n*m) % 2 == 0) {
        cout << (n*m) / 2 << endl;
    } else {
        cout << (n*m) / 2 + 1 << endl;
    }
} 