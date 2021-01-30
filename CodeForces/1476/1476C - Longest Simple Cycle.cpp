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
    int n;
    cin >> n;
    // Col: Length of chain, vertex 1, vertex 2
    vector<vector<int>> chains(n, vector<int> (3, -1));
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> chains[i][j];
        }
    }

    int64_t ans = 0, curr_len = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, curr_len);

        if (chains[i][1] == chains[i][2]) curr_len = 0;

        if (curr_len == 0) {
            curr_len = abs(chains[i][2] - chains[i][1]) + 2 + (chains[i][0] - 1);
        } else {
            int64_t len1 = curr_len - abs(chains[i][2] - chains[i][1]) + 2 + (chains[i][0] - 1);
            int64_t len2 = abs(chains[i][2] - chains[i][1]) + 2 + (chains[i][0] - 1);
            curr_len = max(len1, len2);
        }
    }
    
    cout << max(ans, curr_len) << endl;
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
