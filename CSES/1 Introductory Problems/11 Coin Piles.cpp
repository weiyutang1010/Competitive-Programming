#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 
 
 
void solve() {
    int a, b;
    cin >> a >> b;
 
    if (min(a, b) * 2 < max(a, b)) {
        cout << "NO" << endl;
        return;
    }
 
    ll num = a + b;
    if (num % 3 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
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