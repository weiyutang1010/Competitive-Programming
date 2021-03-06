/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: A.cpp
 * time: Fri Feb 19 14:35:36 2021
 */

#include <bits/stdc++.h>
using namespace std;
const string CP_GEN_FILE = "A";

namespace cp {

}

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) cin >> x;

    int max_n = 0, curr = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            curr++;
            max_n = max(curr, max_n);
        } else {
            curr = 1;
        }
    }

    cout << max(max_n, curr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
