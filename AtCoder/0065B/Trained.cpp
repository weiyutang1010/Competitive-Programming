#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int & x: v) {
        cin >> x;
    }

    int cnt = 0;
    int i = 0;
    while (cnt < n) {
        if (i == 1) {
            cout << cnt << endl;
            return;
        }
        i = v[i] - 1;
        cnt++;
    }
    cout << -1 << endl;
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
