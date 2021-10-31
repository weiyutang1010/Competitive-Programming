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

void solve() {
    int64_t l, r;
    cin >> l >> r;

    cout << r % max(l, r/2 + 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}

