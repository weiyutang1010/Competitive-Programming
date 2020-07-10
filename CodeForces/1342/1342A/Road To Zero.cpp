#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll price1 = (abs(x) * a) + (abs(y) * a);
    ll price2 = (abs(x - y) * a) + (min(abs(x), abs(y)) * b);
    cout << min(price1, price2) << endl;
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
