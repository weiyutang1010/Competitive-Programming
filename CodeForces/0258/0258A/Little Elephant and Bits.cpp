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
    string s;
    cin >> s;

    bool has_zero = false;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!has_zero && i == (int)s.size() - 1) {
            break;
        }
        if (s[i] == '0' && !has_zero) {
            has_zero = true;
            continue;
        }
        cout << s[i];
    }
    cout << endl;

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
