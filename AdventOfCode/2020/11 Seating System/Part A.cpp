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

vector<ii> dir {{0, 1}, {0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
map<ii, int> visited;

void dfs(vector<string>& v, int row, int col, int r_size, int c_size, bool& changed) {
    if (row < 0 || row >= r_size || col < 0 || col >= c_size) {
        return;
    }

    if (visited[make_pair(row, col)]) {
        return;
    }

    visited[make_pair(row, col)] = 1;

    // Check each paths to see if there's visible occupied seats 
    int adj = 0;
    for (ii& x: dir) {
        if (row + x.f >= 0 && row + x.f < r_size && col + x.s >= 0 && col + x.s < c_size) {
            if (v[row + x.f][col+x.s] == '#') {
                adj++;
            }
        }
    }

    // Call dfs on adjacent seats
    for (ii& x: dir) {
        dfs(v, row + x.f, col + x.s, r_size, c_size, changed);
    }

    // Swap seats
    if (v[row][col] == 'L' && adj == 0) {
        v[row][col] = '#';
        changed = true;
    } else if (v[row][col] == '#' && adj >= 4) {
        v[row][col] = 'L';
        changed = true;
    }
}

int main() 
{
    ifstream text("input.txt");
    vector<string> v;
    string st;

    while (cin >> st) {
        v.push_back(st);
    }

    // Keep swapping seat until no more changes
    bool temp = true;
    while (temp) {
        bool changed = false;
        dfs(v, 0, 0, v.size(), v[0].size(), changed);
        visited.clear();
        if (!changed) temp = false;
    }

    // Count occupied seats
    int64_t ans = 0;
    for (auto x: v) {
        for (auto y: x) {
            if (y == '#') ans++;
        }
    }

    cout << ans << endl;

    text.close();
    return 0;
} 
