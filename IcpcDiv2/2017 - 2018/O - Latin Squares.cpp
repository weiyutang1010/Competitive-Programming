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

void solve(int n) {
    vector<string> v(n);
    for (string& st: v) cin >> st;

    map<char, int> mp;
    bool reduced = true;

    // Store digit in first column
    for (int i = 0; i < n; i++) {
        mp[v[i][0]]++;
        if (mp[v[i][0]] > 1) {
            cout << "No" << endl;
            return;
        }
    }

    map<char, int> temp;
    for (int i = 0; i < n; i++) {
        temp = mp;
        for (int j = 0; j < n; j++) {
            temp[v[i][j]]--;
        }

        for (auto& x: temp) {
            if (x.s != 0) {
                cout << "No" << endl;
                return;
            }
        }

    }

    for (int i = 0; i < n; i++) {
        temp = mp;
        for (int j = 0; j < n; j++) {
            temp[v[j][i]]--;
        }

        for (auto& x: temp) {
            if (x.s != 0) {
                cout << "No" << endl;
                return;
            }
        }

    }

    for (int i = 0; i < n-1; i++) {
        if (v[i][0] > v[i+1][0] || v[0][i] > v[0][i+1]) {
            reduced = false;
            break;
        }
    }


    if (reduced) cout << "Reduced" << endl;
    else cout << "Not Reduced" << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    //int t = 1;
    //cin >> t;

    int n;
    while (cin >> n) {
        //cout << "Case #" << i << ": ";
        solve(n);
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
