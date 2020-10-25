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

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v (n, vector<int> (n, 0));
    for (int i = 0, j = 0; i < n; i++, j++) {
        v[i][j] = 1;
    }
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        v[i][j] = 1;
    }

    if (n & 1) {
        v[n / 2 - 1][n / 2] = 1;
        v[n / 2][n / 2 + 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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
