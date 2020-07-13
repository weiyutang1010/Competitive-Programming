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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    int res = 0;
    int cur = 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (cur * v[i] >= x) {
            res++;
            cur = 0;
        }
        cur++;
    }

    cout << res << endl;
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
