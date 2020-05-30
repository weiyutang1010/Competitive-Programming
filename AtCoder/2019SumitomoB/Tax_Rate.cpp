#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define ld long double

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
	int n;
    cin >> n;

    int x = n/1.08;
    int y = ceil(n/1.08);

    if (floor(x * 1.08) == n) {
        cout << x << "\n";
        return;
    } else if (floor(y * 1.08) == n) {
        cout << y << "\n";
        return;
    }

    cout << ":(" << "\n";
}
