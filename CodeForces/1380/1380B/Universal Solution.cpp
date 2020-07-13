/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>

#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 

void solve() {
    vector<char> ch {'R','S','P'};

    string st;
    cin >> st;
    unordered_map<char, int> cnt;
    for (char& x: st) {
        cnt[x]++;
    }

    pair<char, int> max_n {'a', 0};
    int val = cnt['P'];
    bool same = true;
    for (auto x: ch) {
        if (cnt[x] != val) {
            same = false;
        }

        if (cnt[x] > max_n.s) {
            max_n = {x, cnt[x]};
        }
    }

    if (same) {
        cout << st << endl;
    } else {
        if (max_n.f == 'R') {
            max_n.f = 'P';
        } else if (max_n.f == 'P') {
            max_n.f = 'S';
        } else {
            max_n.f = 'R';
        }

        for (int i = 0; i < (int)st.size(); i++) {
            cout << max_n.f;
        }
        cout << endl;
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
