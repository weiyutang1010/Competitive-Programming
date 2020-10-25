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
 
vector<ii> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
 
void dfs(vector<vector<int>>& visited, string& s, int& ans, int i, int j, int curr) {
    if (i == 6 && j == 0) {   
        if (curr == 48) {
            ans++;
        }
        return;
    }
 
    visited[i][j] = 1;
 
    // 1st if check for direction
    // 2nd if check whether path is valid
    // 3rd if check whether it reaches a wall
 
    if (s[curr] == '?' || s[curr] == 'D') {
        if (i < 6 && !visited[i + 1][j]) {
            if (!((i + 2 >= 7 || visited[i + 2][j]) && j > 0 && j < 6 && !visited[i+1][j-1] && !visited[i+1][j+1]))
                dfs(visited, s, ans, i + 1, j, curr + 1); 
        }
    } 
    if (s[curr] == '?' || s[curr] == 'U') {
        if (i > 0 && !visited[i - 1][j]) {
            if (!((i - 2 < 0 || visited[i - 2][j]) && j > 0 && j < 6 && !visited[i-1][j-1] && !visited[i-1][j+1]))
                dfs(visited, s, ans, i - 1, j, curr + 1); 
        }
    }
    if (s[curr] == '?' || s[curr] == 'L') {
        if (j > 0 && !visited[i][j - 1]) { 
            if (!((j - 2 < 0 || visited[i][j - 2]) && i > 0 && i < 6 && !visited[i-1][j-1] && !visited[i+1][j-1]))
                dfs(visited, s, ans, i, j - 1, curr + 1); 
        }
    } 
    if (s[curr] == '?' || s[curr] == 'R') {
        if (j < 6 && !visited[i][j + 1]) { 
            if (!((j + 2 >= 7 || visited[i][j + 2]) && i > 0 && i < 6 && !visited[i-1][j+1] && !visited[i+1][j+1]))
                dfs(visited, s, ans, i, j + 1, curr + 1); 
        }
    } 
 
    visited[i][j] = 0;
    return;
}
 
void solve() {
    string s;
    cin >> s;
    vector<vector<int>> visited (7, vector<int> (7, 0));
    int ans = 0;
 
    dfs(visited, s, ans, 0, 0, 0);
 
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