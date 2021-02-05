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
 
const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }

    for (int i = 0; k > 0; i++) {
        bool found = false;
        int idx = 0;
        for (int j = 0; j < n - 1; j++) {
            if (v[j] < v[j + 1]) {
                idx = j;
                found = true;
                if (j == 0) {
                    k -= v[j + 1] - v[j];
                    v[j] = v[j + 1];
                } else if(v[j-1] == v[j]) {
                    k -= 1;
                    v[j]++;
                } else if (v[j-1] > v[j] && v[j - 1] < v[j + 1]) {
                    k -= v[j - 1] - v[j];
                    v[j] = v[j - 1];
                } else {
                    k -= v[j + 1] - v[j];
                    v[j] = v[j + 1];
                }
                break;
            }
        }
        
        if (k <= 0) {
            cout << idx + 1 << endl;
            found = true;
            return;
        }
        
        if (!found) {
            cout << -1 << endl;
            return;
        }
    }

    if (k > 0) cout << -1 << endl;
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
