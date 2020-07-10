#include <bits/stdc++.h>
#define ll long long
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
}
 
void solve() 
{ 
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> tile;
    tile.resize(n);
    
    char d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d;
            tile[i].push_back(d);
        }
    }
    
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tile[i][j] == '.') {
                if (j < m-1 && tile[i][j+1] == '.') {
                    cost += min(y, 2*x);
                    j++;
                } else {
                    cost += x;
                    j++;
                }
            }
        }
    }
    
    cout << cost << "\n";
}