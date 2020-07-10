#include <bits/stdc++.h>
#define ll long long
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
    int n, m, k;
    cin >> n >> m >> k;
    
    if (n/k >= m) {
        cout << m << "\n";
        return;
    }
    
    int h1 = n/k;
    float h2 = float(m - (n/k))/(k-1);
    
    cout << (int)(h1 - h2) << "\n";
    
}