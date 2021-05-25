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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << "Or not." << endl;
            return;
        }
    } 
    cout << "Odd." << endl;
    return;
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
