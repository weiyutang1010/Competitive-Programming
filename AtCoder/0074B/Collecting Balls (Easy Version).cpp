#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
 
    for (int& x: v) {
        cin >> x;
    }
 
    int mid = k / 2;
 
    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] <= mid) {
            sum += v[i] * 2;
        } else {
            sum += (k - v[i]) * 2;
        }
    }
 
    cout << sum << "\n";
}
 
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