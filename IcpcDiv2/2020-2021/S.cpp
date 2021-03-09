/*
* Team
* D2: Time Limit Exceeded
*/

#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

void backtrack(vector<string>& v, int& ans, vector<int> score, string st, int curr, int k, int n) {    
    if (curr >= k) return;

    for (int i = 0; i < n; i++) {
        if (v[i][curr] == st[curr]) {
            score[i]++;
        }
    }

    if (curr == k - 1) {
        int min_n = INT_MAX;
        for (int i = 0; i < n; i++) {
            min_n = min(min_n, score[i]);
        }
        ans = max(ans, min_n);
        return;
    }

    backtrack(v, ans, score, st + 'T', curr + 1, k, n);
    backtrack(v, ans, score, st + 'F', curr + 1, k, n);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (string& x: v) cin >> x;

    int ans = 0;
    vector<int> score(n, 0);
    backtrack(v, ans, score, "T", 0, k, n);
    backtrack(v, ans, score, "F", 0, k, n);

    

    cout << ans << endl;
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

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
