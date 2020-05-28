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
    // cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() 
{ 
	int x;
    string s;
 
    cin >> x >> s;
 
    if (s.size() <= x) {
        cout << s << "\n";
    } else {
        cout << s.substr(0, x) << "...\n";
    }
}
