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
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cnt[temp1]++; cnt[temp2]++;
    }

    int val = 0;
    for (int i = 1; i <= n; i++) {    
        if (cnt[i] == 0) {
            val = i;
            break;
        }
    }

    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++) {
        if (i != val) {
            cout << val << " " << i << endl;
        }
    }

    return;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    // cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
