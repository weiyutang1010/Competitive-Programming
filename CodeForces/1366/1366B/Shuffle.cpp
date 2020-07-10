#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 

void solve() {
    int n, x, m;
    cin >> n >> x >> m;

    vector<pair<int, int>> v(m);
    for (pair<int, int> &x: v) {
        cin >> x.first;
        cin >> x.second;
    }

    int lp = x, rp = x;
    for (int i = 0; i < m; i++) {
        //cout << "lp: " << lp << " rp: " << rp << endl;
        if (v[i].first > rp || v[i].second < lp) {
            continue;
        }
        lp = min(lp, v[i].first);
        rp = max(rp, v[i].second);
    }

    cout << rp - lp + 1 << endl;
}

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
