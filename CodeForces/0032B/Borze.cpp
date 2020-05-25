#include <bits/stdc++.h>
#define ll unsigned long long int
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
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

void solve() 
{ 
    string s;
    cin >> s;
    
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ans += '0';
        } else {
            if (s[i+1] == '.') {
                ans += '1';
            } else {
                ans += '2';
            }
            i++;
        }
    }
    
    cout << ans << "\n";
} 