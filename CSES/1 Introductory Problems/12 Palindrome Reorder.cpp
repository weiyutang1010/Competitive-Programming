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

void solve() {
    string st;
    cin >> st;
    map<char, int> m;
    for (int i = 0; i < (int)st.size(); i++) {
        m[st[i]]++;
    }

    int odd_cnt = 0;
    for (auto x: m) {
        if (x.s & 1) {
            odd_cnt++;
        }
    }

    if (odd_cnt > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    int i = 0;
    for (auto x: m) {
        if (x.s & 1) {
            st[st.size() / 2] = x.f;
        }

        for (int j = 0; j < x.s / 2; j++) {
            st[i] = x.f;
            st[(int)st.size() - 1 - i] = x.f;
            i++;
        }
    }
    cout << st << endl;
}    

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
