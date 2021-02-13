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
 
void backtrack(set<string> &st, string s, string s1, int curr, int len) {
    if (curr >= (int)s.size()) {
        return;
    }
 
    s1 += s[curr];
    s.erase(s.begin() + curr);
 
    if ((int)s1.size() == len) {
        st.insert(s1);
        return;
    }
 
    for (int i = 0; i < (int)s.size(); i++) {
        backtrack(st, s, s1, i, len);
    }
 
}
 
void solve() {
    string s;
    cin >> s;
    set<string> st;
 
    for (int i = 0; i < (int)s.size(); i++) {
        backtrack(st, s, "", i, s.size());
    }
 
    cout << st.size() << endl;
    for (auto x: st) {
        cout << x << endl;
    }
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