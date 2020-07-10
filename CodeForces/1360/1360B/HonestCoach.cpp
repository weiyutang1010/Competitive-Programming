#include <bits/stdc++.h> 
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
    /*is Single Test case?*/ cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() 
{ 
    int num_p;
    vector<int> p;
    int num;
    int ans = INT_MAX;
    
    cin >> num_p;
    for (int i = 0; i < num_p; i++) {
        cin >> num;
        p.push_back(num);
    }
    
    //cout << "mid: " << mid << endl;
    for (int i = 0; i < num_p - 1; i++) {
        for (int j = i + 1; j < num_p; j++) {
            ans = min(ans, abs(p[i] - p[j]));
        }
    }
    
    
    
    cout << ans << "\n";
} 