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
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() 
{ 
    int x, y;
    cin >> x >> y;
    
    string q;
    cin >> q;
    
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x - 1; j++) {
            if (q[j] == 'B' && q[j+1] == 'G') {
                q[j] = 'G';
                q[j+1] = 'B';
                j++;
            }
        }
    }
    
    cout << q << "\n";
} 