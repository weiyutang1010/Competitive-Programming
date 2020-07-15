#include <bits/stdc++.h>

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
	int n;
    cin >> n;

    ulli temp;
    ulli sum = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        sum += temp;
    }


    ulli ans = (((ulli)n * (n+1)) / 2) - sum;
    cout << ans << "\n";
}
