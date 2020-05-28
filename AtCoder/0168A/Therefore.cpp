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
    cin >> x ;
 
    if (x%10 == 2 || x%10 == 4 || x%10 == 5 || x%10 == 7 || x%10 == 9) {
        cout << "hon\n";
    } else if (x%10 == 0 || x%10 == 1 || x%10 == 6 || x%10 == 8) {
        cout << "pon\n";
    } else {
        cout << "bon\n";
    }
}
