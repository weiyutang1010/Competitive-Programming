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

//brute force and trying out all options. since the max value is only 1024.

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }

    sort(v.begin(), v.end());
    bool is_equal = true;
    int i;
    for (i = 1; i <= 1024; i++) {
        vector<int> ans (n);
        for (int j = 0; j < n; j++) {
           ans[j] = v[j] ^ i; 
        } 
        sort(ans.begin(), ans.end());

        is_equal = true;
        for (int j = 0; j < n; j++) {
            if (v[j] != ans[j]) {
                is_equal = false;
                break;
            }
        }

        if (is_equal) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n"; 
    

}
