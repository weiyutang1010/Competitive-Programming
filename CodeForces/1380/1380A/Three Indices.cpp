/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>

#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
    
    for (int i = 0; i < n - 2; i++) {
        if (v[i] < v[i+1] && v[i+1] > v[i+2]) {
            cout << "YES" << endl;
            cout << i+1 << " " << i+2 << " " << i+3 << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
