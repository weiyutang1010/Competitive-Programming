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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);

    unordered_map<int, int> fence; // color: index
    for (int& x: a) cin >> x;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        fence[b[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    };

    int cnt = 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            mp[b[i]].push_back(i);
            cnt++;
        }
    }
    
    // paint required fence
    // if no required fence, check if any fence has the same color
    int right_pt = 0;
    vector<int> paint(m, -1);
    for (int i = 0; i < m; i++) {
        if (mp[c[i]].size() > 0) {
            paint[i] = mp[c[i]].back();
            mp[c[i]].pop_back();
            cnt--;
            right_pt = i;
        } else if (fence[c[i]]) {
            paint[i] = fence[c[i]] - 1;
            right_pt = i;
        }
    }

    if (cnt > 0) {
        cout << "NO" << endl;
        return;
    }

    // For still unmatched painter, check following:
    // paint the same fence as anyone to the right
    for (int i = 0; i < m; i++) {
        bool found = false;
        if (paint[i] == -1) {
            if (i < right_pt) {
                paint[i] = paint[right_pt];
                found = true;
            }

            if (!found) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
        cout << paint[i] + 1 << " ";
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
