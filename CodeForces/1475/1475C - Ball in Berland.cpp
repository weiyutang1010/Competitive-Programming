/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: C.cpp
 * time: Fri Feb 19 14:35:40 2021
 */

#include <bits/stdc++.h>
using namespace std;
const string CP_GEN_FILE = "C";

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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v1(k), v2(k);
    unordered_map<int64_t, int> boy_count;
    unordered_map<int64_t, int> girl_count;
    for (int i = 0; i < k; i++) {
        cin >> v1[i];
        boy_count[v1[i]]++;
    }
    for (int i = 0; i < k; i++) {
        cin >> v2[i];
        girl_count[v2[i]]++;
    };

    int64_t ans = 0;
    for (int i = 0; i < k; i++) {
        ans += k - boy_count[v1[i]] - girl_count[v2[i]] + 1;
    }

    cout << ans / 2 << endl;
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
