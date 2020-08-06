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
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans(n);
    vector<int> pos0, pos1;

    for (int i = 0; i < n; i++) {
        int new_pos = pos0.size() + pos1.size();
        if (s[i] == '0') {
            if (pos1.empty()) {
                pos0.push_back(new_pos);
            } else {
                new_pos = pos1.back();
                pos1.pop_back();
                pos0.push_back(new_pos);
            }
        } else {
            if (pos0.empty()) {
                pos1.push_back(new_pos);
            } else {
                new_pos = pos0.back();
                pos0.pop_back();
                pos1.push_back(new_pos);
            }
        }

        ans[i] = new_pos;
    }

    cout << pos0.size() + pos1.size() << endl;
    for (int& x: ans) {
        cout << x + 1 << " ";
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
