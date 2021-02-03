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
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    string st;
    cin >> st;

    unordered_map<char, int> m;
    for (char& c: st) {
        m[c]++;
    }

    int ans = 0;
    // paper - rock
    ans += min(b, m['R']);
    // rock - sciccors
    ans += min(a, m['S']);
    // sciccors - paper
    ans += min(c, m['P']);

    if (ans >= ceil(n / 2.0)) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (a && st[i] == 'S') st[i] = 'R', a--;
            else if (b && st[i] == 'R') st[i] = 'P', b--;
            else if (c && st[i] == 'P') st[i] = 'S', c--;
            else st[i] = 'G';
        }

        for (int i = 0; i < n; i++) {
            if (st[i] == 'G') {
                if (a) st[i] = 'R', a--;
                else if (b) st[i] = 'P', b--;
                else if (c) st[i] = 'S', c--;
            }
        }
        cout << st << endl;
    } else {
        cout << "NO" << endl;
    }

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
