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

struct sort_pred {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3)); // store height, width, index
    for (int i = 0; i < n; i++) {
        v[i][2] = INT_MAX;
        cin >> v[i][0] >> v[i][1];
        sort(v[i].begin(), v[i].end()); //swap h and w so width is the larger number
        v[i][2] = i;
    }

    /*
        sort it so that left is in decreasing order. If height are the same, sort by width in increasing order
        e.g. 9   7   4
             6   10  2
             6   11  0
             3   3   1
             3   4   5
             2   4   3
    */
    sort(v.begin(), v.end(), sort_pred());

    // Pre calculate the lowest width after current height
    // lowest width using example above from top to bottom: 3 3 3 3 4 4
    vector<ii> prefix_min(n, make_pair(v[n - 1][1], v[n - 1][2])); //store width, index
    for (int i = n-1; i > 0; i--) {
        if (prefix_min[i].f < v[i - 1][1]) {
            prefix_min[i - 1] = prefix_min[i];
        } else {
            prefix_min[i - 1] = make_pair(v[i - 1][1], v[i - 1][2]);
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (prefix_min[i].f < v[i][1]) {
            ans[v[i][2]] = prefix_min[i].s + 1;
        }
    }
    for (int& x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
