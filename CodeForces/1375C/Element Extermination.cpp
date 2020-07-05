#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << ((v[n - 1] > v[0]) ? "YES" : "NO") << endl;
}