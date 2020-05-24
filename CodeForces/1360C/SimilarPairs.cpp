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
    int num;
    int x;
    int odd = 0;
    int even = 0;
    vector<int> v;
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> x;
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        v.push_back(x);
    }
    
    if (min(odd,even) == 0) {cout << "YES\n"; return;}
    
    if (even % 2 == 1 && odd % 2 == 1) {
        for (int i = 0; i < num - 1; i++) {
            for (int j = i + 1; j < num; j++) {
                if (v[i] % 2 != v[j] % 2 && abs(v[j] - v[i]) == 1) {
                    //cout << "num1: " << v[i] << " num2: " << v[j] << endl;
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    
} 