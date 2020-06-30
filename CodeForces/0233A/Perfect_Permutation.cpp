#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int x;
    cin >> x;

    if (x & 1) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < (x >> 1); i++) {
        cout << (i * 2) + 2 << " " << (i * 2) + 1 << " "; 
    }
    cout << endl;
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
