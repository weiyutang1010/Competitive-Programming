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
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() 
{ 
    int num;
    cin >> num;
    
    vector<int> v;
    int y = 0;
    for (int i = 0; i < num; i++) {
        cin >> y;
        v.push_back(y);
    }
    
    map<int, int> m;
    int sum = 1;
    
    for (int i = 0; i < num; i++) {
        m[v[i]] += 1;
    }
    
    int p = 0;
    for (auto x: m) {
        p += x.second;
        if (sum + p > x.first) {
            sum += p;
            p = 0;
        }
    }
    
    cout << sum << "\n";
} 