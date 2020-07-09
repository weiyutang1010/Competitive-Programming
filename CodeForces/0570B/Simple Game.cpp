/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
using namespace std; 

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (m <= n/2) {
        cout << m + 1 << endl;
    } else {
        cout << m - 1 << endl;
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
