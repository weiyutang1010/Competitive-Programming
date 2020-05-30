#include <bits/stdc++.h>
#include <cmath>

#define ulli unsigned long long int
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
	ulli h, w;
    cin >> h >> w;

    if (h == 1 || w == 1) {
        cout << 1 << "\n";
        return;
    }

    ulli area = h*w;

    ulli ans = (area & 1) ? (area / 2) + 1 : (area / 2);

    cout << ans << "\n";
}
