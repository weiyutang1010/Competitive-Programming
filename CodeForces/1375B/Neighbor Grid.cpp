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

vector<ii> dir {{1,0}, {0,1}, {-1,0}, {0,-1}};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int> (m, 0));
    for (vector<int>& x: grid) {
        for (int& y: x) {
            cin >> y;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int possible = 0;
            for (auto x: dir) {
                if (i + x.f >= 0 && j + x.s >= 0 && i + x.f < n && j + x.s < m) {
                    possible++;
                }
            }
            if (grid[i][j] > possible) {
                cout << "NO" << endl;
                return;
            }
            grid[i][j] = possible;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
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
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
