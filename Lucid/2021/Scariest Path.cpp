/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: A.cpp
 * time: Fri Feb 19 14:35:40 2021
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<ii> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int& x: v) cin >> x;

    vector<vector<int>> adj_mat(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
        }
    }

    vector<ii> deg;
    for (int i = 0; i < n; i++) {
        deg.push_back({v[i], i});
    }

    sort(deg.begin(), deg.end());

    int ans = 0;
    unordered_map<int, bool> mp;
    for (int i = n-1; i >= 0; i--) {    
        int idx = deg[i].s;

        ans += v[idx];
        for (int j = 0; j < n; j++) {
            if (adj_mat[idx][j] && mp[j]) {
                ans += v[j]; 
            }
        }
        mp[idx] = 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
