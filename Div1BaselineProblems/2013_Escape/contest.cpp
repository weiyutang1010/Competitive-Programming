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

vector<ii> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
map<ii, bool> visited;

int dfs(vector<string>& v, vector<vector<int>>& dp, map<char, int>& m, int row, int col, int w, int h, int curr, int& count) {
    count++;
    cout << count << endl;

    if (row < 0 || row >= h || col < 0 || col >= w) {
        return curr;
    }

    // if (dp[row][col]) {
    //     return dp[row][col];
    // }

    int ans = 0;
    //curr += m[v[row][col]];
    for (ii& d: dir) {
        ans = min(ans, dfs(v, dp, m, row + d.f, col + d.s, w, h, curr, count));
    }


    //dp[row][col] = ans;
    return ans;
}


void solve() {
    int k, w, h;
    cin >> k >> w >> h;
    map<char, int> m;
    vector<vector<int>> dp(h, vector<int> (w, 0));

    for (int i = 0; i < k; i++) {
        char a; int b;
        cin >> a >> b;
        m[a] = b;
    }

    vector<string> v(h);
    for (int i = 0; i < h; i++) {
         cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == 'E') {
                dfs(v, dp, m, i, j, w, h, 0, count);
                return;
            }
        }
    }
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t;
    t = 1;

    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
