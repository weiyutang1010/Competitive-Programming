#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 
 
void solve() {
    ll n, k;
    cin >> n >> k;
 
    if (n == k) {
        cout << "0" << endl;
    } else if (n < k) {
        cout << min(n, abs(n - k)) << endl;
    } else {
        if (n % k == 0) {
            cout << 0 << endl;
        } else {
            cout << fixed;
            cout << (ll)min(abs(n-floor(n/(ld)k) * k), abs(n - ceil(n/(ld)k) * k)) << endl;
        }
    }
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