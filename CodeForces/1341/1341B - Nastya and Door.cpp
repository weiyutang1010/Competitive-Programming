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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& x: v) cin >> x;

    vector<int> peak(n, 0);
    for (int i = 1; i < n - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            peak[i] = 1;
        }
    }

    int num_peak = 0;
    for (int i = 1; i < k - 1; i++) {
        if (peak[i]) num_peak++;
    }

    int max_p = num_peak, min_l = 0;
    for (int i = 1; i < n - k + 1; i++) {
        if (peak[i]) num_peak--;
        if (peak[i + k - 2]) num_peak++;
        if (num_peak > max_p) {
            min_l = i;
            max_p = num_peak;
        }
    }

    cout << max_p + 1 << " " << min_l + 1 << endl;
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
