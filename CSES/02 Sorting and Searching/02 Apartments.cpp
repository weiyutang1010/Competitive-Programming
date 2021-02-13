/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 

const int INF = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int& x: a) {
        cin >> x;
    }
    for (int& x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        //cout << a[i] << " " << b[j] << endl;

        if (abs(b[j] - a[i]) <= k) {
            ans++; i++; j++;
        } else if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        }
    }

    cout << ans << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
