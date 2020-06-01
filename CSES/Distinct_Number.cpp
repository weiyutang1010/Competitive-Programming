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
  
//#ifndef ONLINE_JUDGE 
//    freopen("input.txt", "r", stdin); 
//    freopen("error.txt", "w", stderr); 
//    freopen("output.txt", "w", stdout); 
//#endif 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() {
    set<ll> ans;
    ll length;
    ll temp;
    
    cin >> length;
    for (int i = 0; i < length; i++) {
        cin >> temp;
        ans.insert(temp);
    }

    cout << ans.size() << "\n";
}

