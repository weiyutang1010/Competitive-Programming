/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: B.cpp
 * time: Fri Feb 19 14:35:38 2021
 */

#include <bits/stdc++.h>
using namespace std;
const string CP_GEN_FILE = "B";

namespace cp {

}

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

int MOD = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int n = abs(b - a) * 2;

    if (a > n || b > n || c > n) {
        cout << -1 << endl;
        return;
    }

    if (c - abs(b - a) < 1) {
        cout << c + abs(b - a) << endl;
    } else {
        cout << c - abs(b - a) << endl;
    }
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

