#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"



void solve() {
    int n;
    cin >> n;
    vector<int64_t> v(n);
    int64_t sum = 0;
    int64_t max_n = 0;
    for (int64_t& x: v) {
        cin >> x;
        sum += x;
        max_n = max(max_n, x);
    }

    cout << min(sum / 2, sum - max_n) << endl;
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
