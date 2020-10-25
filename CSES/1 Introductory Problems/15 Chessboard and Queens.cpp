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

void backtrack(vector<string> v, int& ans, int i, int placed) {
    if (placed == 8) {
        ans++;
        return;
    } else if (i == 8) {
        return;
    }

    backtrack(v, ans, i + 1, placed);
    if (v[placed][i] == '.') {
        for (int j = 0; j < 8; j++) {
            v[j][i] = '*';
        }

        for (int j = 0; placed + j < 8 && i + j < 8; j++) {
            v[placed + j][i + j] = '*';
        }

        for (int j = 0; placed + j < 8 && i - j >= 0; j++) {
            v[placed + j][i - j] = '*';
        }
        backtrack(v, ans, 0, placed + 1);
    }

}

void solve() {
    vector<string> v(8);
    for (string& x: v) {
        cin >> x;
    }
    
    int ans = 0;
    backtrack(v, ans, 0, 0);

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
