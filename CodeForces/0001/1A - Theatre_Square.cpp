#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
void solve(); 
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

//For each side, we either have enough or need one more tile to cover the whole side.
//If it needs one more tile, it will be a decimal number
//We just need to round up the number of tile need to cover each side
//And multiply them together
void solve() {
    int n, m , a;
    cin >> n >> m >> a;

    ll row = ceil(m/(float)a);
    ll col = ceil(n/(float)a);

    cout << row * col << "\n";
}
