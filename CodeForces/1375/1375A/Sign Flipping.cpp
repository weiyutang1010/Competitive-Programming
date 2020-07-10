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
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() {
    int n;
    cin >> n;
    
    vector<ll> v(n);
    cin >> v[0];
    int pos = 0, neg = 0;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        if (v[i] - v[i - 1] > 0) {
            pos++;
        } else if (v[i] - v[i - 1] < 0) {
            neg++;
        } else {
            pos++; neg++;
        }
    }
    
    int i = 0;
    while ((pos < ((n - 1) / 2) || neg < ((n - 1) / 2)) && i < n) {
        v[i] *= -1;
        i++;
        
        pos = 0;
        neg = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] - v[i - 1] > 0) {
                pos++;
            } else if (v[i] - v[i - 1] < 0) {
                neg++;
            } else {
                pos++; neg++;
            }
        }
    }
    
    // cout << "pos: " << pos << " neg: " << neg << endl;
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}